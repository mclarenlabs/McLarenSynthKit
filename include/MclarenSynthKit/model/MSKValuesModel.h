/** -*- mode:objc -*-
 *
 * This model manages a miscellaneous collection of values.
 * Use it as a scratchpad of properties backed with
 * variables that can be saved and restored
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import <Foundation/Foundation.h>

#import "MclarenSynthKit/model/MSKModelBase.h"
#import "MclarenSynthKit/model/MSKModelProtocol.h"

@interface MSKValuesModel : MSKModelBase<MSKModelProtocol> {
  @public

  unsigned int _note1;
  unsigned int _note2;
  unsigned int _note3;
  unsigned int _note4;
  unsigned int _note5;
  unsigned int _note6;
  unsigned int _note7;
  unsigned int _note8;

  int _control1;
  int _control2;
  int _control3;
  int _control4;
  int _control5;
  int _control6;
  int _control7;
  int _control8;

  double _double1;
  double _double2;
  double _double3;
  double _double4;
  double _double5;
  double _double6;
  double _double7;
  double _double8;
}

@property (nonatomic, readwrite, getter=getNote1, setter=setNote1:) NSNumber *note1;
@property (nonatomic, readwrite, getter=getNote2, setter=setNote2:) NSNumber *note2;
@property (nonatomic, readwrite, getter=getNote3, setter=setNote3:) NSNumber *note3;
@property (nonatomic, readwrite, getter=getNote4, setter=setNote4:) NSNumber *note4;
@property (nonatomic, readwrite, getter=getNote5, setter=setNote5:) NSNumber *note5;
@property (nonatomic, readwrite, getter=getNote6, setter=setNote6:) NSNumber *note6;
@property (nonatomic, readwrite, getter=getNote7, setter=setNote7:) NSNumber *note7;
@property (nonatomic, readwrite, getter=getNote8, setter=setNote8:) NSNumber *note8;

@property (nonatomic, readwrite, getter=getControl1, setter=setControl1:) NSNumber *control1;
@property (nonatomic, readwrite, getter=getControl2, setter=setControl2:) NSNumber *control2;
@property (nonatomic, readwrite, getter=getControl3, setter=setControl3:) NSNumber *control3;
@property (nonatomic, readwrite, getter=getControl4, setter=setControl4:) NSNumber *control4;
@property (nonatomic, readwrite, getter=getControl5, setter=setControl5:) NSNumber *control5;
@property (nonatomic, readwrite, getter=getControl6, setter=setControl6:) NSNumber *control6;
@property (nonatomic, readwrite, getter=getControl7, setter=setControl7:) NSNumber *control7;
@property (nonatomic, readwrite, getter=getControl8, setter=setControl8:) NSNumber *control8;

@property (nonatomic, readwrite, getter=getDouble1, setter=setDouble1:) NSNumber *double1;
@property (nonatomic, readwrite, getter=getDouble2, setter=setDouble2:) NSNumber *double2;
@property (nonatomic, readwrite, getter=getDouble3, setter=setDouble3:) NSNumber *double3;
@property (nonatomic, readwrite, getter=getDouble4, setter=setDouble4:) NSNumber *double4;
@property (nonatomic, readwrite, getter=getDouble5, setter=setDouble5:) NSNumber *double5;
@property (nonatomic, readwrite, getter=getDouble6, setter=setDouble6:) NSNumber *double6;
@property (nonatomic, readwrite, getter=getDouble7, setter=setDouble7:) NSNumber *double7;
@property (nonatomic, readwrite, getter=getDouble8, setter=setDouble8:) NSNumber *double8;


- (id) initWithName:(NSString*)name; // for save/restore

- (BOOL) save:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;
- (BOOL) restore:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;

@end

