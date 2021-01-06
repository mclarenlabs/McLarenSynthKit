/**
 * ALSA Metronome
 *
 * The metronome widget provides a time base.  It uses the ALSA
 * Sequencer interface to generate high resolution events.  It accepts
 * control via methods, and also start/stop/continue events via its
 * ALSA control port.
 * 
 * The metronome allocates an ASKSeq with a first port for sending note
 * events and receiving MIDI start/stop/continue events.  It allocates a
 * second port for sending itself internal timing events.
 *
 * A Metronome is configured via its model, and it observes the model
 * using KVO for realtime parameter changes.
 *
 * copyright (c) McLaren Labs 2021
 *
 * Jan 2019
 */

#import "AlsaSoundKit/ASKSeq.h"
#import "MclarenSynthKit/model/MSKMetronomeModel.h"

typedef void (^MSKMetronomeListener)(int beat, int measure);
typedef void (^MSKMetronomeClockListener)(int clock, int beat, int measure); // 0..23
typedef void (^MSKMetronomeStartListener)();
typedef void (^MSKMetronomeStopListener)();

@interface MSKMetronome : NSObject

@property (readonly) MSKMetronomeModel *model; // how to adjust the metronome parameters

@property (readonly) ASKSeq *seq;	    // the sequencer object
@property (readonly) snd_seq_t *seq_handle; // sequencer handle
@property (readonly) int seq_queue;	    // sequencer queue
@property (readonly) int seq_port;	    // sequencer default port
@property (readonly) int cport;		    // metronome control port
@property (readonly) int num;		    // time signature numerator
@property (readonly) int den;		    // time signature denominator
@property (readonly) int queue_tempo;	    // queue tempo in ticks
@property (readonly) int queue_resolution;  // ticks per beat
@property (readonly) int measure;	    // measure count

// private - signal callback
@property (readonly, copy) MSKMetronomeListener beatBlock;
@property (readonly, copy) MSKMetronomeClockListener clockBlock;
@property (readonly, copy) MSKMetronomeStartListener startBlock;
@property (readonly, copy) MSKMetronomeStopListener stopBlock;

- (id) initWithModel:(MSKMetronomeModel*) model error:(NSError**)error;

- (void) start;
- (void) stop;
- (void) kontinue;

// to register a signal handler
- (void) onBeat:(MSKMetronomeListener)block;
- (void) onClock:(MSKMetronomeClockListener)block;
- (void) onStart:(MSKMetronomeStartListener)block;
- (void) onStop:(MSKMetronomeStopListener)block;

@end
