/** -*- mode:objc -*-
 *
 * ObjC wrapper for Freeverb algorithm.
 *
 *
 * Original 
 *  Written by Jezar at Dreampoint, June 2000
 *  http://www.dreampoint.co.uk
 *  This code is public domain
 *
 * copyright (c) McLaren Labs 2021
 */

#import "MclarenSynthKit/MSKContext.h"
// #import "FVTuning.h"
// #import "FVComb.h"
// #import "FVAllpass.h"
#import "MclarenSynthKit/model/MSKReverbModel.h"

@interface MSKFreeverbReverb : MSKContextVoice
- (id) initWithCtx:(MSKContext*)c;
- (void) mute;

BOOL CFMSKFreeverbReverbSing(__unsafe_unretained MSKFreeverbReverb *v, uint64_t now, snd_pcm_sframes_t nframes);

// adjust parameters: do this on PCM thread
- (void) setroomsize:(float)value;
- (float) getroomsize;
- (void) setdamp:(float)value;
- (float) getdamp;

- (void) setwet:(float)value;
- (float) getwet;
- (void) setdry:(float)value;
- (float) getdry;

- (void) setwidth:(float)value;
- (float) getwidth;

		     
// property: input
@property (nonatomic, readwrite, setter=setIInput:, getter=getIInput) MSKContextVoice *sInput;
		     
// the model
@property (nonatomic, readwrite) MSKReverbModel *model;


@end

