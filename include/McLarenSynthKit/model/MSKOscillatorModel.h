/** -*- mode:objc -*-
 *
 * A model manages settings for oscillators.
 * This model will contain a superset of all possible oscillator parameters.
 *
 * $copyright$
 */

#import <Foundation/Foundation.h>

#import "McLarenSynthKit/model/MSKModelBase.h"
#import "McLarenSynthKit/model/MSKModelProtocol.h"

typedef enum msk_oscillator_type {
  MSK_OSCILLATOR_TYPE_SIN,
  MSK_OSCILLATOR_TYPE_SAW,
  MSK_OSCILLATOR_TYPE_SQUARE,
  MSK_OSCILLATOR_TYPE_TRIANGLE,
  MSK_OSCILLATOR_TYPE_REVSAW,
  MSK_OSCILLATOR_TYPE_NONE
} msk_oscillator_type_enum;

#define MSK_OSCILLATOR_MAXTONES 10		// for organ overtones

@interface MSKOscillatorModel : MSKModelBase<MSKModelProtocol> {

  @public
  // for reading in the audio loop
  msk_oscillator_type_enum _osctype;
  int _octave;
  int _transpose;
  int _cents;
  int _bendwidth;
  double _pitchbend;
  int _pw;			// 5..95
  double _modulation;
  int _noise;                   // 0..100
  double _cutoff;               // freq

  // the two MIDI sensitivy switches
  int _pitchbendsw;
  int _modulationsw;

  // for FM Synth
  double _harmonic;
  double _subharmonic;

  // configuration
  int _organ;			// YES,NO
  int _overtones;		// how many overtones
  int _numerators[MSK_OSCILLATOR_MAXTONES];
  int _denominators[MSK_OSCILLATOR_MAXTONES];

  // continuous updates
  double _amplitudes[MSK_OSCILLATOR_MAXTONES];
}

			     
// the properties of the model
@property (nonatomic, readwrite, getter=getOsctype, setter=setOsctype:) NSNumber *osctype;
@property (nonatomic, readwrite, getter=getOctave, setter=setOctave:) NSNumber *octave;
@property (nonatomic, readwrite, getter=getTranspose, setter=setTranspose:) NSNumber *transpose;
@property (nonatomic, readwrite, getter=getCents, setter=setCents:) NSNumber *cents;
@property (nonatomic, readwrite, getter=getBendwidth, setter=setBendwidth:) NSNumber *bendwidth;
@property (nonatomic, readwrite, getter=getPitchbendsw, setter=setPitchbendsw:) NSNumber *pitchbendsw;
@property (nonatomic, readwrite, getter=getPitchbend, setter=setPitchbend:) NSNumber *pitchbend;
@property (nonatomic, readwrite, getter=getPw, setter=setPw:) NSNumber *pw;
@property (nonatomic, readwrite, getter=getModulationsw, setter=setModulationsw:) NSNumber *modulationsw;
@property (nonatomic, readwrite, getter=getModulation, setter=setModulation:) NSNumber *modulation;
@property (nonatomic, readwrite, getter=getNoise, setter=setNoise:) NSNumber *noise;
@property (nonatomic, readwrite, getter=getCutoff, setter=setCutoff:) NSNumber *cutoff;

@property (nonatomic, readwrite, getter=getHarmonic, setter=setHarmonic:) NSNumber *harmonic;
@property (nonatomic, readwrite, getter=getSubharmonic, setter=setSubharmonic:) NSNumber *subharmonic;

@property (nonatomic, readwrite, getter=getOrgan, setter=setOrgan:) NSNumber *organ;
@property (nonatomic, readwrite, getter=getOvertones, setter=setOvertones:) NSNumber *overtones;

// the drawbar values
@property (nonatomic, readwrite, getter=getAmp0, setter=setAmp0:) NSNumber *amp0;
@property (nonatomic, readwrite, getter=getAmp1, setter=setAmp1:) NSNumber *amp1;
@property (nonatomic, readwrite, getter=getAmp2, setter=setAmp2:) NSNumber *amp2;
@property (nonatomic, readwrite, getter=getAmp3, setter=setAmp3:) NSNumber *amp3;
@property (nonatomic, readwrite, getter=getAmp4, setter=setAmp4:) NSNumber *amp4;
@property (nonatomic, readwrite, getter=getAmp5, setter=setAmp5:) NSNumber *amp5;
@property (nonatomic, readwrite, getter=getAmp6, setter=setAmp6:) NSNumber *amp6;
@property (nonatomic, readwrite, getter=getAmp7, setter=setAmp7:) NSNumber *amp7;
@property (nonatomic, readwrite, getter=getAmp8, setter=setAmp8:) NSNumber *amp8;

- (id) initWithName:(NSString*)name; // for save/restore

- (BOOL) save:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;
- (BOOL) restore:(NSUserDefaults*)dict withPrefix:(NSString*)prefix;

@end
