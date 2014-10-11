//
//  NUToDoTableViewController.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "NUToDoTableViewController.h"
#import "ToDo.h"

@interface NUToDoTableViewController ()<UIAlertViewDelegate>

@property RLMArray * todos;

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
}


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
    td.toDoId = @"";
    [self addToListNewToDo:td];
    
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
