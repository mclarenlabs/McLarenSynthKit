/** -*- mode:objc -*-
 *
 * An extension to GeneralOscillator: a phase distortion input is added
 *
 * $copyright$
 *
 */

#import "McLarenSynthKit/MSKContext.h"
#import "McLarenSynthKit/voice/MSKGeneralOscillator.h"

@interface MSKPhaseDistortionOscillator : MSKGeneralOscillator {
  // oscillator properties
  double _modulation;
}

// the phasedistortion
@property (nonatomic, readwrite) MSKContextVoice *sPhasedistortion;

BOOL CFMSKPhaseDistortionOscillatorInit(__unsafe_unretained MSKPhaseDistortionOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKPhaseDistortionOscillatorControls(__unsafe_unretained MSKPhaseDistortionOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKPhaseDistortionOscillatorSing(__unsafe_unretained MSKPhaseDistortionOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
				 

@end
