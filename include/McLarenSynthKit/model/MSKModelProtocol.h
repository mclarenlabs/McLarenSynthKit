/** -*- mode:objc -*-
 *
 * The save/restore protocol that models must implement.
 *
 * $copyright$
 *
 */

#import <Foundation/Foundation.h>

@protocol MSKModelProtocol

- (BOOL) save:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;
- (BOOL) restore:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;

@end
