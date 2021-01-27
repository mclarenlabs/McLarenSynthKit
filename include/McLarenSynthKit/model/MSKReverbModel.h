/** -*- mode:objc -*-
 *
 * A model manages settings for reverb units.
 *
 * $copyright$
 *
 */

#import <Foundation/Foundation.h>
#import "McLarenSynthKit/model/MSKModelBase.h"
#import "McLarenSynthKit/model/MSKModelProtocol.h"

@interface MSKReverbModel : MSKModelBase<MSKModelProtocol> {
  @public
  int _on;			// reverb on/off
  double _dry;
  double _wet;
  double _roomsize;
  double _damp;
}

// the properties of the model
@property (nonatomic, readwrite, getter=getOn, setter=setOn:) NSNumber *on;
@property (nonatomic, readwrite, getter=getDry, setter=setDry:) NSNumber *dry;
@property (nonatomic, readwrite, getter=getWet, setter=setWet:) NSNumber *wet;
@property (nonatomic, readwrite, getter=getRoomsize, setter=setRoomsize:) NSNumber *roomsize;
@property (nonatomic, readwrite, getter=getDamp, setter=setDamp:) NSNumber *damp;

- (id) initWithName:(NSString*)name; // for save/restore

- (BOOL) save:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;
- (BOOL) restore:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;

@end
