/** -*- mode:objc -*-
 *
 * A model managing the settings for a Metronome
 *
 * $copyright$
 *
 */

#import <Foundation/Foundation.h>

#import "McLarenSynthKit/model/MSKModelBase.h"
#import "McLarenSynthKit/model/MSKModelProtocol.h"

/*
 * This object is used to set/get timesig values from the model
 */

@interface MSKMetronomeModelTimesig : NSObject

@property (readwrite) int num;
@property (readwrite) int den;

+ (MSKMetronomeModelTimesig*) timesigWithNum:(int)num den:(int)den;
@end

/*
 * The metronome model manages the settings of the metronome and emits change signals
 * via the observer pattern.
 */

@interface MSKMetronomeModel : MSKModelBase<MSKModelProtocol> {
  @public
  double _bpm;
  int _num;
  int _den;
}

// the properties of the model
@property (nonatomic, readwrite, getter=getBpm, setter=setBpm:) NSNumber *bpm;
@property (nonatomic, readwrite, getter=getTimesig, setter=setTimesig:) MSKMetronomeModelTimesig *timesig;

- (id) initWithName:(NSString*)name; // for save/restore

- (BOOL) save:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;
- (BOOL) restore:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;

@end

