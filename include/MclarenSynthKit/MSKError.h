/** -*- mode:objc -*-
 *
 * Error codes and Error objects for McLaren Synth Kit
 *
 * copyright (c) McLaren Labs 2021
 */

#import <Foundation/Foundation.h>

/*
 * Error Handling
 */

extern NSString *MSKContextErrorDomain;

typedef NS_ENUM(NSInteger, MSKContextErrorEnum) {
    kMSKContextError = 0,
      kMSKContextErrorIllegalValue,
      kMSKContextErrorCannotConfigureDevice,
      kMSKContextErrorIllegalState,
      kMSKContextErrorInternalConsistencyError,
      kMSKContextErrorThreadStoppedUnexpectedly
};

@interface NSError(MSKContext)
+ errorWithMSKContextError:(int)err str:(NSString*)str; /* error from ASND enum */
+ errorWithMSKContextError:(int)err str:(NSString*)str under:(NSError*)under;
@end


void MSKError_linker_function(); // to force linkage of NSError category