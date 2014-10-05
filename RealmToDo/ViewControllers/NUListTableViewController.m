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
#import "NUSyncEngine.h"

@interface NUListTableViewController ()<UIAlertViewDelegate>

@property RLMArray * lists;


// Action on the add button pressed on the top right
- (IBAction)onListAdd:(id)sender;

@property RLMNotificationToken * token;

@end

@implementation NUListTableViewController

List * selectedList;

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self getLists];
    [self addNotificationToRealmUpdates];
    
    //If user not logged in then open the login view
    if([APUser currentUser ] == nil){
        [self presentViewController:[self.storyboard instantiateViewControllerWithIdentifier:@"login"] animated:NO completion:nil ]; 
    }

    //Else start the sync
    else{

        [[NUSyncEngine sharedNUSyncEngine] startSync];
    }
}


-(void) addNotificationToRealmUpdates{
    RLMRealm *realm = [RLMRealm defaultRealm];

    self.token = [realm addNotificationBlock:^(NSString *note, RLMRealm * realm) {
        [self getLists];
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/




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
    l.isSyncd = 1;
    [self addListToRealm:l];
    
    [[NUSyncEngine sharedNUSyncEngine] addedList:l];
}

-(void) addListToRealm:(List *) list{
    RLMRealm *realm = [RLMRealm defaultRealm];
    
    [realm beginWriteTransaction];
    [realm addObject:list];
    [realm commitWriteTransaction];
}

@end
