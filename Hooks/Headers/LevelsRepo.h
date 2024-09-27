#import <UIKit/UIKit.h>

@interface CustomNavigationViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, retain) NSArray *customLevels;
@property (nonatomic, retain) NSDictionary *selectedCustomLevel;
@end
