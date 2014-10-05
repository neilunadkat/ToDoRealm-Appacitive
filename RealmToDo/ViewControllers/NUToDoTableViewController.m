//
//  NUToDoTableViewController.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "NUToDoTableViewController.h"
#import "ToDo.h"
#import "NUSyncEngine.h"

@interface NUToDoTableViewController ()<UIAlertViewDelegate>

@property RLMArray * todos;

// Action on the add button pressed on the top right
- (IBAction)onTodoAdd:(id)sender;

@property RLMNotificationToken * token;

@end

@implementation NUToDoTableViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    [self getTodos];
    [self addNotificationToRealmUpdates];
}

-(void) addNotificationToRealmUpdates{
    RLMRealm *realm = [RLMRealm defaultRealm];
    
    self.token = [realm addNotificationBlock:^(NSString *note, RLMRealm * realm) {
        //Whenever there are changes in Realm call this.
        [self getTodos];
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
    if(_todos == nil)
        return 0;
    
    // Return the number of rows in the section.
    return [_todos count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"todo_cell" forIndexPath:indexPath];
    
    
    ToDo * todo = (ToDo *)[_todos objectAtIndex:indexPath.row];
    UILabel * name = (UILabel *) [cell viewWithTag:1];
    NSString * text = todo.text;
    if(todo.completed == YES){
        NSMutableAttributedString *attributeString = [[NSMutableAttributedString alloc] initWithString:text];
        [attributeString addAttribute:NSStrikethroughStyleAttributeName
                                value:@2
                                range:NSMakeRange(0, [attributeString length])];
        name.attributedText = attributeString;
    }
    else{
    name.text = todo.text;
    }
    // Configure the cell...
    
    return cell;
}

- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    ToDo * td = (ToDo *) [_todos objectAtIndex:indexPath.row];
    BOOL status;
    if(td.completed == NO){
        status = YES;
    }
    else{
        status = NO;
    }
    [self updateTodo:td withCompleted:status];
    [[NUSyncEngine sharedNUSyncEngine] updatedTodo:td];
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


-(void) getTodos{
    _todos = _list.toDos;
    [self.tableView reloadData];
}

- (IBAction)onTodoAdd:(id)sender {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Add todo"
                                                    message:@"Enter name of new todo"
                                                   delegate:self
                                          cancelButtonTitle:@"Done"
                                          otherButtonTitles:nil];
    alert.alertViewStyle = UIAlertViewStylePlainTextInput;
    [alert show];
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    NSString * todo = [alertView textFieldAtIndex:0].text;
    NSLog(@"%@", todo);
    
    ToDo * td = [[ToDo alloc] init];
    td.text = todo;
    td.completed = NO;
    td.isSyncd = 1;
    [self addToListNewToDo:td];
    
    [[NUSyncEngine sharedNUSyncEngine] addedTodo:td ToList:_list];
    
}

- (void) updateTodo:(ToDo *) td withCompleted:(BOOL) status{
    RLMRealm *realm = [RLMRealm defaultRealm];
    
    [realm beginWriteTransaction];
    td.completed = status;
    [realm commitWriteTransaction];
}

- (void) addToListNewToDo:(ToDo *) todo{
    RLMRealm *realm = [RLMRealm defaultRealm];
    

    [realm beginWriteTransaction];
    [_list.toDos addObject:todo];
    [realm commitWriteTransaction];
}
@end
