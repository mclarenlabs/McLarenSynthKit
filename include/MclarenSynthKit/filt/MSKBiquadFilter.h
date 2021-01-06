/** -*- mode:objc -*-
 *
 * Biquad Filter with input sInput and configuration properties.
 *
 * Ref: http://www.earlevel.com/main/2012/11/26/biquad-c-source-code/
 *
 * Note: Modified to take Fc in units of Hz.
 *
 * copyright (c) McLaren Labs 2021
 *
 */

#import "MclarenSynthKit/MSKContext.h"

enum {
    MSK_BIQUAD_TYPE_LOWPASS = 0,
    MSK_BIQUAD_TYPE_HIGHPASS,
    MSK_BIQUAD_TYPE_BANDPASS,
    MSK_BIQUAD_TYPE_NOTCH,
    MSK_BIQUAD_TYPE_PEAK,
    MSK_BIQUAD_TYPE_LOWSHELF,
    MSK_BIQUAD_TYPE_HIGHSHELF
};


@interface MSKBiquadFilter : MSKContextVoice

// property: type
@property (nonatomic, readwrite, setter=setIType:, getter=getIType) NSNumber *iType;

// property: Fc in Hertz
@property (nonatomic, readwrite, setter=setIFc:, getter=getIFc) NSNumber *iFc;

// property: Q
@property (nonatomic, readwrite, setter=setIQ:, getter=getIQ) NSNumber *iQ;

// property: peakGainDB
@property (nonatomic, readwrite, setter=setIPeakGainDB:, getter=getIPeakGainDB) NSNumber *iPeakGainDB;

// property: input
@property (nonatomic, readwrite) MSKContextVoice *sInput;


- (id) initWithCtx:(MSKContext*)c;

BOOL CFMSKBiquadFilterSing(__unsafe_unretained MSKBiquadFilter *v, uint64_t now, snd_pcm_sframes_t nframes);

+ (MSKBiquadFilter*) filterWithLowpass:(MSKContext*)ctx; // pre-made LPF filter

@end

