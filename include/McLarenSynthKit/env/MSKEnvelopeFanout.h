/** -*- mode:objc -*-
 *
 * An Envelope Fanout re-sends the envelope protocol methods (noteOff, noteAbort
 * and noteReset) to a collection of envelopes. 
 *
 * $copyright$
 *
 */

#import "McLarenSynthKit/MSKContext.h"

@interface MSKEnvelopeFanout : MSKContextVoice<MSKContextEnvelope>

@property (readwrite) MSKContextVoice<MSKContextEnvelope> *env1;
@property (readwrite) MSKContextVoice<MSKContextEnvelope> *env2;
@property (readwrite) MSKContextVoice<MSKContextEnvelope> *env3;
@property (readwrite) MSKContextVoice<MSKContextEnvelope> *env4;

- (id) initWithCtx:(MSKContext*)c;
- (BOOL) noteOff;
- (BOOL) noteAbort;
- (BOOL) noteReset:(int)idx;

BOOL CFMSKEnvelopeFanoutSing(__unsafe_unretained MSKEnvelopeFanout *v, uint64_t now, snd_pcm_sframes_t nframes);

@end
