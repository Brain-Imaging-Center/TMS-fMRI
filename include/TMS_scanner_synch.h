/* Header file for the TMS-scanner synchronization. */

    #ifndef TMS_SCANNER_SYNCH_H

      #define  PULSE_LENGTH   10  // Units of microseconds. TMS TrigIn port needs a pulse width of at least 10 us.
      #define  TRIG_TO_TMS_PULSE_DELAY   215  // There are 215 microsecond delay from the time the trigger is
                                              // sent to the TMS unit to the time the of the center of the TMS
                                              // pulse delivery. We measured this with an oscilloscope and the
                                              // Magventure B field probe. This delay is accounted for in the
                                              // code of sys_main.

      typedef struct TMS_struct
      {
    	unsigned int trig_image_vol;
    	unsigned int num_trigs_in_train;
        unsigned long int trig_time[10];
      } TMS_struct;


    #define TMS_SCANNER_SYNCH_H
    #endif



