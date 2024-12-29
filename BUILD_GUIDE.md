# RVPC Build Guide

To assemble our RVPC, we will follow the recommended order of assembly in the original [user manual](./DOCUMENTS/RVPC-user-manual.pdf), adding a few extra clarifications, photos and tips.

Here is an overview from the manual showing the front side of the board once fully completed, highlighting the key components:

<img src="./IMAGES/overview.png" width="30%">

## Basics - THT vs SMT

## Key points

- Pay attention to the orientation of the CH32V003 chip
- Don't forgot to bridge the red, green or blue terminals on the back of the board - otherwise nothing will appear on the screen!
- Use a 5V power supply only. 9V or higher will burn your RVPC. We use a standard phone charger and a USB to barrel jack cable.

## Getting Started - Step 0: Laying Out the Components 

Here is a summary Bill of Materials (BOM) of all the components of the RVPC, in the recommended order of assembly.

Now is a good time to open up the bag, familiarise yourself with each component and check everything is there 

[table]

| Step | Number | Code | Description |
|------|--------|------|-------------|
| 1    | 1      | --   | Printed Circuit Board |
| 2    | 1      | U1   | CH32V003J4M6(SOP8) |
| 3    | 1      | R7   | 100R/1/8W BROWN-BLACK-BROWN-GOLD |
| 4    | 3      | R2, R3, R4 | 470R/1/8W YELLOW-PURPLE-BROWN |
| 5    | 4      | R1, R5, R6, R8 | 2k/1/8W RED-BLACK-RED-GOLD |
| 6    | 1      | D1   | 1N4148/DO35 The black line mark to K(square pad) |
| 7    | 1      | C1   | 100nF/25V/2010 104 |
| 8    | 1      | T1   | 2N3904 N-P-N transistor |
| 9    | 1      | PWR_LED1 | LED/PTH/5MM/RED Longest pin to A(round pad) |
| 10    | 1      | SPK1 | QMB-09B-03(1.5-5.0V_2.7kHz) Speaker |
| 11   | 1      | PGM/DBG1 | HN1x2 2 pin header |
| 12   | 1      | PS2_KBD1 | MDR6_MINI-DIN PS2 connector |
| 13   | 1      | VGA1 | HDR15-3.08-14.5T/VGA15 VGA connector |
| 14   | 1      | PWR_JACK1 | PWRJ-2mm(YDJ-1134) Power Jack |

## Step 1: Inspecting the Printed Circuit Board

First take a good look at the PCB, to differentiate the front and back sides. All components are placed on the front side of the board.

Front side:
<img src="./IMAGES/step0_pcb_front.jpg" width="30%">

Back side:
<img src="./IMAGES/step0_pcb_back.jpg" width="30%">

## Step 2: CH32V003 RISC-V Microcontroller Unit (MCU)

<img src="./IMAGES/step1_component.jpg" width="30%">

- This is marked U1 on the board and it will be the brains of our PC
- It is the trickiest element to solder correctly!
- It is a surface-mount (SMT) component meaning it is soldered to the front side of the board only
- Orientation of the chip _matters_. There is a small black circle on the chip itself, which should orient towards the white circle on the board

Help the others on your table to get this right!

There are two ways to approach this one. Whichever method you choose, it's good to have a pair of tweezers at hand...

### Method 1: Hot plate

We have set up a table with a mini hot plate if you want to try this method. The process goes as follows:

<img src="./IMAGES/step1_method1_hot_plate.jpg" width="30%">
<img src="./IMAGES/step1_method1_solder_paste.jpg" width="30%">

1. Place the RVPC circuit board on the hot plate
2. Place a small amount of solder paste on each of the U1 pads
3. Then heat the hot plate to the and wait until you you see the 

### Method 2: Soldering iron with fine tip

Start with the top left pin

It helps to have an extra person to hold the component in place with the tweezers, leaving you both hands free to hold the iron in place and apply the solder. 

From this point on you can continue on your own, soldering the bottom right pin, then all the remaining pins.

Apply heat to the pad and the leg together, not just the leg

Be careful not overapply solder (thinner solder helps here).

### Method 3: Hot-air rework station

This is another alternative to try, which we don't have at the congress, sadly...

## Basics of THT soldering

Congratulations, from here on in it gets easier! The rest of the components in the build are all through-hole and a bit more human-friendly to work with. We can 

following method:

## Step 3: 100R Resistor

1. Place the legs/pin through the holes on the front side of the board
2. Flip the board (whilst holding the component in place)
3. Bend the legs/pins to secure the position of the component
NOTE: bending to little means the component can slip back, but bending too much makes the leg/pin harder to snip off
<img src="./IMAGES/step2_led bend.jpg" width="30%">

4. Soldering
	- it's good to flip the board after soldering, as 
	after two or more pins are solder, it gets trickier

5. Snipping
NOTE: turn the board away from you and others before performing the snip, as can hit you in the eye

If you are new to soldering, we recommend going . If you have more experience you may wish to batches

<img src="./IMAGES/step2_component.jpg" width="30%">

- There is one of these, marked R7 on the board
- The colour code on each resistor shows: BROWN-BLACK-BROWN-GOLD

## Step 4: 470R Resistor

<img src="./IMAGES/step3_component.jpg" width="30%">

- There are 3 of these, marked R2, R3 and R4 on the board
- The colour code on each resistor shows: YELLOW-PURPLE-BROWN
- Orientation does not matter, it can be soldered either way round

## Step 5: 2k Resistor

<img src="./IMAGES/step4_component.jpg" width="30%">

- There are 4 of these, marked R1, R5, R6 and R8 on the board
- The colour code on each resistor shows: RED-BLACK-RED-GOLD
- Orientation does not matter, it can be soldered either way round

## Step 6: 1N4148 Diode

<img src="./IMAGES/step5_component.jpg" width="30%">

- There is just one of these, marked D1 on the board.
- Orientation here _does_ matter, the black line on the diode should align with
-- the white line
-- where the K is printed
-- the square pad

## Step 7: 100nF Cermamic Capacitor

<img src="./IMAGES/step6_component.jpg" width="30%">

- There is just one of these, marked C1 on the board
- It can be identified by the number 104 printed on it

## Step 8: 2N3904 NPN Transistor

<img src="./IMAGES/step7_component.jpg" width="30%">

- There is just one of these, marked T1 on the board
- Orientation here _does_ matter - insert the transistor to match silk screen marking on the board

## Step 9: 5mm Red LED

<img src="./IMAGES/step8_component.jpg" width="30%">

- There is just one of these, marked PWR_LED1 on the board
- Orientation here _does_ matter, the longest leg should go through the round pad (closest to the side marked A)

## Step 10: Speaker

<img src="./IMAGES/step9_component.jpg" width="30%">

- There is just one of these, marked SPK1 on the board
- Orientation here _does_ matter, the leg marked with a plus sign (+) should go to the corresponding hole also marked with a plus sign (square pad)

## Step 11: 2-pin Programming Header

<img src="./IMAGES/step10_component.jpg" width="30%">

- There is just one of these, marked PGM/DBG1 on the board
- Orientation doesn't matter
- Be sure to solder to the front side, the same as all other components

## Step 12: PS2 Keyboard Connector

<img src="./IMAGES/step11_component.jpg" width="30%">

- There is just one of these, marked PS2_KBD1 on the board
- It can only be oriented one way
- The larger pins at either side are mounting points, but you should

## Step 13: VGA Connector

<img src="./IMAGES/step12_component.jpg" width="30%">

- There is just one of these, marked VGA1 on the board
- It can only be oriented one way

## Step 14: Power Jack Connector

<img src="./IMAGES/step13_component.jpg" width="30%">

There is just one of these, marked PWR_JACK1 on the board
# Programming using Raspberry Pi Pico

You will need a Raspberry Pi with pin headers. We used a (Pico 1)[https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html#pico-1-technical-specification]

## Step 15: Bridging

- On the back side of the board, close to the VGA connector, you will see three pairs of small pads
- These define the colour that will be used 
- If you don't connect at least one of these pairs, nothing will diplays
- In our experience, more than one can set of pads can be bridged

[photo]

## Step 16: First test

We have set up two testing stations in the Hardware Hacking Area - head there when you have completed your build.

Use a 5V USB power bank or phone charger and a USB to barrel jack cable

When plugged/powered, the LED should light and the speaker should emit a short startup sound.

You can test. 

It's normal for the screen to flicker

Not all VGA monitors work, we found that older lower resolution monitors have a better chance to succeed.