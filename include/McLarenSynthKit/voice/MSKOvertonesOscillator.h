/** -*- mode:objc -*-
 *
 * Oscillator with overtones.
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import "MclarenSynthKit/MSKContext.h"
#import "MclarenSynthKit/model/MSKOscillatorModel.h"

@interface MSKOvertonesOscillator : MSKContextVoice {

  unsigned _rate;

  // primary configuration parameters
  int _osctype;

  // note properties
  double _freq;
  int _note;
  int _octave;
  int _transpose;
  int _cents;
  double _bend;
  unsigned int _bendwidth;
  double _pw;
  double _modulation;
}

// the Note
@property (nonatomic, readwrite) NSNumber *iNote;

// the model
@property (nonatomic, readwrite) MSKOscillatorModel *model;

// the envelope
@property (nonatomic, readwrite, ) MSKContextVoice<MSKContextEnvelope> *sEnvelope;


- (id) initWithCtx:(MSKContext*)c;

BOOL CFMSKOvertonesOscillatorInit(__unsafe_unretained MSKOvertonesOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKOvertonesOscillatorControls(__unsafe_unretained MSKOvertonesOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKOvertonesOscillatorSing(__unsafe_unretained MSKOvertonesOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);

@end

