/*
 * A Voice renders a sound to its context
 *
 * $copyright$
 */

#import "McLarenSynthKit/MSKContext.h"
#import "McLarenSynthKit/model/MSKOscillatorModel.h"

/*
 * an MSKSinFixedOscillator renders sound based on its attached models and its input buffers.
 */

@interface MSKSinFixedOscillator : MSKContextVoice {
  double _freq;
  double _phi;
  double _dphi;
}

// the frequency initial value
@property (readwrite) NSNumber *iFreq;

// the envelope sample input
@property (nonatomic, readwrite) MSKContextVoice *sEnvelope;

- (id) initWithCtx:(MSKContext*)c;

BOOL CFMSKSinFixedOscillatorInit(__unsafe_unretained MSKSinFixedOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKSinFixedOscillatorControls(__unsafe_unretained MSKSinFixedOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKSinFixedOscillatorSing(__unsafe_unretained MSKSinFixedOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);

@end

