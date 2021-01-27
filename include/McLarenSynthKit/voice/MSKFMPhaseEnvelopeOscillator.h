/** -*- mode:objc -*-
 *
 * An FM Oscillator with an additional envelope input that controls the magnitude
 * of the modulation.
 *
 * out[i] = SIN(\phi + 3.5 * M * pi[i] * SIN(\psi))
 *  where \psi = \phi * (HARMONIC/SUBHARMONIC)
 *
 * $copyright$
 */

#import <Foundation/Foundation.h>
#import "McLarenSynthKit/MSKContext.h"
#import "McLarenSynthKit/model/MSKOscillatorModel.h"

@interface MSKFMPhaseEnvelopeOscillator : MSKContextVoice

// the Note
@property (nonatomic, readwrite) NSNumber *iNote;

// the model
@property (nonatomic, readwrite) MSKOscillatorModel *model;

// the envelope
@property (nonatomic, readwrite) MSKContextVoice<MSKContextEnvelope> *sEnvelope;

// the phase envelope
@property (nonatomic, readwrite) MSKContextVoice<MSKContextEnvelope> *sPhaseenvelope;

- (id) initWithCtx:(MSKContext*)c;

BOOL CFMSKFMPhaseEnvelopeOscillatorInit(__unsafe_unretained MSKFMPhaseEnvelopeOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKFMPhaseEnvelopeOscillatorControls(__unsafe_unretained MSKFMPhaseEnvelopeOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKFMPhaseEnvelopeOscillatorSing(__unsafe_unretained MSKFMPhaseEnvelopeOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);

@end
