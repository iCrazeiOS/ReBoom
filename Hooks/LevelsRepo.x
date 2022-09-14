/*
	Adds a table view to CustomNavigationViewController.
	Used to display the list of available custom levels.
*/

#import "Headers/Main.h"

%hook CustomNavigationViewController
%property (nonatomic, retain) NSArray *customLevels;
%property (nonatomic, retain) NSDictionary *selectedCustomLevel;

-(void)viewDidLoad {
	%orig;
	NSData *urlContents = [NSData dataWithContentsOfURL:[NSURL URLWithString:@"https://raw.githubusercontent.com/iCrazeiOS/ReBoom-Levels/main/Levels.json"]];
	if (urlContents) {
		NSJSONSerialization *json = [NSJSONSerialization JSONObjectWithData:urlContents options:0 error:nil];
		if (json) {
			// sort the levels by name
			self.customLevels = [(NSArray *)json sortedArrayUsingDescriptors:[NSArray arrayWithObject:[[NSSortDescriptor alloc] initWithKey:@"display_name" ascending:YES]]];
		} else self.customLevels = @[@{@"display_name": @"Error", @"author": @"Could not parse JSON", @"filename": @""}];
	} else self.customLevels = @[@{@"display_name": @"Error", @"author": @"Could not fetch JSON", @"filename": @""}];
}

%new
-(int)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [self.customLevels count];
}

%new
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
	if (!cell) cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"cell"];
	cell.textLabel.text = self.customLevels[indexPath.row][@"display_name"];
	cell.detailTextLabel.text = self.customLevels[indexPath.row][@"author"];
	return cell;
}

%new
-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	self.selectedCustomLevel = self.customLevels[indexPath.row];
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 0.1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		[tableView deselectRowAtIndexPath:indexPath animated:YES];
		[tableView removeFromSuperview];
	});
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if ([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"]) %init;
}
