/** -*- mode:objc -*-
 *
 * An envelope produces a buffer of values in [0 .. 1.0]
 *
 * This envelope generator is inspired by code from Nigel Redmon
 * http://www.earlevel.com/main/2013/06/01/envelope-generators
 *
 * The clever insight that Nigel had was that instead of computing time, this tracks
 * the levels and transitions when the value goes above and below 0 and 1.0.
 *
 * The TargetRatio values are as so: lower (near zero) is more
 * exponential, higher is more linear.
 *
 * The code here uses units of seconds.
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import "MclarenSynthKit/MSKContext.h"
#import "MclarenSynthKit/model/MSKEnvelopeModel.h"

@interface MSKExpEnvelope : MSKContextVoice<MSKContextEnvelope>

// for a oneshot envelope
@property (nonatomic, readwrite) BOOL oneshot;
@property (nonatomic, readwrite) double shottime;

// the initial Gain - usually related to velocity
@property (nonatomic, readwrite, setter=setIGain:, getter=getIGain) NSNumber *iGain;

// the model: ADSR
@property (nonatomic, readwrite) MSKEnvelopeModel *model;

// Lower ratios are more exponential, higher values tend toward linear
@property (nonatomic, readwrite, setter=setITargetRatioA:, getter=getITargetRatioA) NSNumber *iTargetRatioA;
@property (nonatomic, readwrite, setter=setITargetRatioDR:, getter=getITargetRatioDR) NSNumber *iTargetRatioDR;

- (id) initWithCtx:(MSKContext*)c;

// implements the MSKContextEnvelope protocol
- (BOOL) noteOff;
- (BOOL) noteAbort;
- (BOOL) noteReset:(int)idx;

// declaration of implementations
BOOL CFMSKExpEnvelopeSetControls(__unsafe_unretained MSKExpEnvelope *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKExpEnvelopeSing(__unsafe_unretained MSKExpEnvelope *v, uint64_t now, snd_pcm_sframes_t nframes);

@end
