/** -*- mode:objc -*-
 *
 * An envelope produces a buffer of values in [0 .. 1.0]
 *
 * This envelope linearly transitions from point to point.
 * 
 * $copyright$
 *
 */

#import "McLarenSynthKit/MSKContext.h"
#import "McLarenSynthKit/model/MSKEnvelopeModel.h"

@interface MSKLinEnvelope : MSKContextVoice<MSKContextEnvelope>

@property (nonatomic, readwrite) BOOL oneshot;
@property (nonatomic, readwrite) double shottime;

// the initial Gain
@property (nonatomic, readwrite, setter=setIGain:, getter=getIGain) NSNumber *iGain;

// the model
@property (nonatomic, readwrite) MSKEnvelopeModel *model;

- (id) initWithCtx:(MSKContext*)c;

// implements the MSKContextEnvelope protocol
- (BOOL) noteOff;
- (BOOL) noteAbort;
- (BOOL) noteReset:(int)idx;

// declaration of implementations
BOOL CFMSKLinEnvelopeSetControls(__unsafe_unretained MSKLinEnvelope *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKLinEnvelopeSing(__unsafe_unretained MSKLinEnvelope *v, uint64_t now, snd_pcm_sframes_t nframes);

@end
