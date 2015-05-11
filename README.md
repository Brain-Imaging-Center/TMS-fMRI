# TMS-fMRI
This directory contains code for a Texas Instruments Hercules microcontroller board. The microcontroller and code are responsible for sending triggers to the MagVenture TMS unit and synchronizing these triggers with the Siemens MRI scanner. 

The code does the following (Specifics are documented with the code.):

(I) Initializes the microcontroller (see sys_main.c).

(II) Reads a file called TMS_trig_data (see sys_main.c). This file is created by the user and controls the timing of the triggers sent to the TMS unit. The TMS_trig_data must be located in the TMS_trig_files subdirectory of the code. The file contains on each line: (1) The EPI volume number during which the trigger should be sent to the TMS unit, (2) The number of triggers in a train of triggers associated with that particular volume, and (3) The time (in microseconds) at which you would like the triggers in the train sent to the TMS unit relative to the MRI scanner TTL pulse associated with that volume. Please see TMS_trig_data_1 as an example. The TTL pulse from the scanner occurs prior to the MRI scanner's slice selection RF pulse. Please see the wiki page associated with this GitHub repository for more information about when the scanner TTL is sent relative to other scanner events.

(III) Receives the TTL pulse signal from the MRI scanner. This signal produces a hardware interrupt in the microcontroller (see the gioNotification() function in the file notification.c). The associated interrupt service routine (ISR) named gioNotification() does the following: (1) Counts these interrupts, (2) Sets the leading edge of the first rectangular 10 microsecond trigger pulse in the train of triggers associated with a particular volume designated in the TMS_trig_data file and (3) Schedules the trailing edge of the first trigger of the train of triggers associated with a particular EPI volume (This is done by using hardware interrupts associated with the real-time interrupt system of the microcontroller).

(IV) Schedules successive leading and trailing edges of the rest of the triggers in a train associated with a particular EPI volume. This is done by using using hardware interrupts associated with the real-time interrupt system of the microcontroller. See the rtiNotification() ISR in the sys_main.c file.

To run the code you will need to install Code Composer Studio (CCS) on a PC. CCS is available free of cost through Texas Instruments at http://www.ti.com/tool/ccstudio. Once CCS is installed you may download the code in this repository and run it by doing the following:

(1) Open CCS.
(2) Click on the project directory.
(3) Click Run->Debug

This will compile, erase and then load (flash) the code to the microcontroller. You must do this each time you run the code.



