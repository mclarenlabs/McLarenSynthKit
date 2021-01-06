/** -*- mode:objc -*-
 *
 * Oscillator waveform generalized to SIN, SAW, SQUARE, TRIANGLE, REVSAW
 *
 * This oscillator may be continuously updated through its model.
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import "MclarenSynthKit/MSKContext.h"
#import "MclarenSynthKit/model/MSKOscillatorModel.h"

@interface MSKGeneralOscillator : MSKContextVoice {

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
  int _noise;
    
  // oscillator properties
  double _phi;
  double _dphi;
  double _modulo;
  double _incr;

  // hack: allow model to be accessed in child class MSKPhaseDistortionOscillator
  @public
  MSKOscillatorModel *_model;

}

// the initial Note
@property (nonatomic, readwrite) NSNumber *iNote;

// the model
@property (nonatomic, readwrite) MSKOscillatorModel *model;

// the envelope
@property (nonatomic, readwrite) MSKContextVoice<MSKContextEnvelope> *sEnvelope;

- (id) initWithCtx:(MSKContext*)c;

BOOL CFMSKGeneralOscillatorInit(__unsafe_unretained MSKGeneralOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKGeneralOscillatorControls(__unsafe_unretained MSKGeneralOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);
BOOL CFMSKGeneralOscillatorSing(__unsafe_unretained MSKGeneralOscillator *v, uint64_t now, snd_pcm_sframes_t nframes);

void CFMSKGeneralOscillatorIncrModulo(__unsafe_unretained MSKGeneralOscillator *v); // used by PDVoice
@end

