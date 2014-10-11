//
//  NUListTableViewController.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "NUListTableViewController.h"
#import "List.h"
#import <Appacitive/AppacitiveSDK.h>
#import "NUToDoTableViewController.h"

@interface NUListTableViewController ()<UIAlertViewDelegate>

@property RLMArray * lists;

- (IBAction)onListAdd:(id)sender;

@property RLMNotificationToken * token;

@end

@implementation NUListTableViewController

List * selectedList;

- (void)viewDidLoad
{
    [super viewDidLoad];
    if([APUser currentUser ] == nil){
        [self presentViewController:[self.storyboard instantiateViewControllerWithIdentifier:@"login"] animated:NO completion:nil ];
    }
    [self getLists];
    [self addNotificationToRealmUpdates];
}


-(void) addNotificationToRealmUpdates{
    RLMRealm *realm = [RLMRealm defaultRealm];

    self.token = [realm addNotificationBlock:^(NSString *note, RLMRealm * realm) {
        [self getLists];
    }];
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(_lists == nil)
        return 0;
    // Return the number of rows in the section.
    return [_lists count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"list_cell" forIndexPath:indexPath];
 
    List * list = (List *)[_lists objectAtIndex:indexPath.row];
    UILabel * name = (UILabel *) [cell viewWithTag:1];
    name.text = list.name;
    // Configure the cell...
    
    return cell;
}


#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    NSIndexPath *path = [self.tableView indexPathForSelectedRow];
    
    NUToDoTableViewController * todoVC = (NUToDoTableViewController *) [segue destinationViewController];
    todoVC.list = (List *) [_lists objectAtIndex:path.row];;
}


- (void) getLists{
    _lists = [List allObjects];
    [self.tableView reloadData];
}

- (IBAction)onListAdd:(id)sender {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Add list"
                                                    message:@"Enter name of new list"
                                                   delegate:self
                                          cancelButtonTitle:@"Done"
                                          otherButtonTitles:nil];
    alert.alertViewStyle = UIAlertViewStylePlainTextInput;
    [alert show];
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    NSString * listName =[alertView textFieldAtIndex:0].text;
    NSLog(@"%@", listName);
    List *l = [[List alloc] init];
    l.name =listName;
    
    l.listId = @"";
    [self addListToRealm:l];
}

-(void) addListToRealm:(List *) list{
    RLMRealm *realm = [RLMRealm defaultRealm];
    
    [realm beginWriteTransaction];
    [realm addObject:list];
    [realm commitWriteTransaction];
}

@end
