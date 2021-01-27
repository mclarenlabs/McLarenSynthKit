/** -*- mode:objc -*-
 *
 * Model for Envelopes
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import <Foundation/Foundation.h>
#import "MclarenSynthKit/model/MSKModelBase.h"
#import "MclarenSynthKit/model/MSKModelProtocol.h"

/*
 * When an envelope is repeated from the beginning, rhythmically, we
 * call that a stutter.
 */

typedef enum msk_envelope_stutter_type : NSUInteger {
  MSK_ENVELOPE_STUTTER_NONE,
    MSK_ENVELOPE_STUTTER_WHOLE,
    MSK_ENVELOPE_STUTTER_HALF,
    MSK_ENVELOPE_STUTTER_QUARTER,
    MSK_ENVELOPE_STUTTER_EIGTH,
    MSK_ENVELOPE_STUTTER_SIXTEENTH,
    MSK_ENVELOPE_STUTTER_TRIPLET
} msk_envelope_stutter_type_t;

/*
 * An Envelope Model holds parameters that envelope generators use.
 */

@interface MSKEnvelopeModel : MSKModelBase<MSKModelProtocol> {
@public
  BOOL _linear;
  msk_envelope_stutter_type_t _stutter;
  double _attack;
  double _decay;
  double _sustain;
  double _rel;
  double _sens;
}

// the properties of the model
@property (nonatomic, readwrite, getter=getLinear, setter=setLinear:) NSNumber *linear;
@property (nonatomic, readwrite, getter=getStutter, setter=setStutter:) NSNumber *stutter;
@property (nonatomic, readwrite, getter=getAttack, setter=setAttack:) NSNumber *attack;
@property (nonatomic, readwrite, getter=getDecay, setter=setDecay:) NSNumber *decay;
@property (nonatomic, readwrite, getter=getSustain, setter=setSustain:) NSNumber *sustain;
@property (nonatomic, readwrite, getter=getRel, setter=setRel:) NSNumber *rel; // 'release' is a reserved word
@property (nonatomic, readwrite, getter=getSens, setter=setSens:) NSNumber *sens; // sensitivity of gain to velocity

- (id) initWithName:(NSString*)name;

- (BOOL) save:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;
- (BOOL) restore:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;

// utility: compute envelope iGain [0..1.0] as a function of note velocity [0..127] and sens
- (NSNumber*) iGainForVel:(uint8_t)vel;

@end
