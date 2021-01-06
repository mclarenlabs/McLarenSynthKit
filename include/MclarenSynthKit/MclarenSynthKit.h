/**
 * Umbrella include for McLaren Synth Kit
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import "MclarenSynthKit/MSKContext.h"
#import "MclarenSynthKit/MSKError.h"
#import "MclarenSynthKit/MSKMetronome.h"

#import "MclarenSynthKit/env/MSKEnvelopeFanout.h"
#import "MclarenSynthKit/env/MSKExpEnvelope.h"
#import "MclarenSynthKit/env/MSKLinEnvelope.h"

#import "MclarenSynthKit/filt/MSKBiquadFilter.h"

#import "MclarenSynthKit/fx/MSKFreeverbReverb.h"

#import "MclarenSynthKit/model/MSKEnvelopeModel.h"
#import "MclarenSynthKit/model/MSKMetronomeModel.h"
#import "MclarenSynthKit/model/MSKModelBase.h"
#import "MclarenSynthKit/model/MSKModelProtocol.h"
#import "MclarenSynthKit/model/MSKOscillatorModel.h"
#import "MclarenSynthKit/model/MSKReverbModel.h"
#import "MclarenSynthKit/model/MSKValuesModel.h"

#import "MclarenSynthKit/voice/MSKFMPhaseEnvelopeOscillator.h"
#import "MclarenSynthKit/voice/MSKGeneralOscillator.h"
#import "MclarenSynthKit/voice/MSKOvertonesOscillator.h"
#import "MclarenSynthKit/voice/MSKPhaseDistortionOscillator.h"
#import "MclarenSynthKit/voice/MSKSinFixedOscillator.h"
