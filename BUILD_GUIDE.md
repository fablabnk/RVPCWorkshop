# RVPC Build Guide

To assemble our RVPC, we will follow the recommended order of assembly in the original [user manual](./DOCUMENTS/RVPC-user-manual.pdf), adding a few extra clarifications, photos and tips.

Here is a photo showing the front side of the board once fully completed, highlighting the key components.

<img src="./IMAGES/overview.png" width="30%">

## Basics - soldering tips

## Basics - THT vs SMT

## Key points

- Oir
- Don't forgot to bridge 
- Don't use a 9V or - you will burn your RVPC


## Getting Started: Laying Out the Components 

Here is a summary - or Bill of Materials (BOM) - of all the components of the RVPC, in the recommended order of assembly.

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

## Step 1: Printed Circuit Board

Front side:
<img src="./IMAGES/step0_pcb_front.jpg" width="30%">

Back side
<img src="./IMAGES/step0_pcb_back.jpg" width="30%">

Good time to familiarise. All components are mounted on the front


## Step 2: CH32V003 RISC-V Microcontroller Unit (MCU)

<img src="./IMAGES/step1_component.jpg" width="30%">

- This first component of the build is also perhaps the trickiest one to solder correctly. 

- There is just one of these, marked U1 on the board and it will be the brains of our PC.

- Orientation is important


Not only does it have the smallest legs, it also differs from the others because it is a surface-mount (SMT) not through-hole (THT) component, meaning it is soldered to to front side of the board only.

If you are new to soldering, you may wish to skip ahead and start with one of the easier components, but be aware that the more of the other components you solder, the trickier it will be to - and you will not be able to use the hot plate method below.

There are two ways to approach this one. Whichever method you choose, it's good to have a pair of tweezers at hand

Sneeze, you lose

### Method 1: Hot plate

We have set up a table at the Hardware Hacking Area with a mini hot plate if you want to try this method

1. Place the RVPC circuit board on the hot plate
2. Place a small amount of solder paste on each of the U1 pads
3. Then heat the hot plate to the and wait until you you see the 

### Method 2: Soldering iron with fine tip

head

### Method 3: Hot-air rework station

This is another alternative to try, which we don't have at the congress, sadly...

## Step 3: 100R Resistor

Congratulations, from here on in it gets easier! All the rest of the components in the build are through-hole (THT) and a bit more human-friendly to work with. We insert them by

1. Placing their legs through the holes on the front side of the board
	- front side is the one which has graphics of the components themselves
2. Flipping the board (whilst holding the component in place)
3. Bending the legs to secure the position of the component
NOTE: bending

<img src="./IMAGES/step2_led bend.jpg" width="30%">

4. Soldering
	- it's good to flip the board after soldering, as 
	after two or more pins are solder, it gets trickier

5. Snipping
NOTE: turn the board away from you and others before performing the snip, as can hit you in the eye

If you are new to soldering, we recommend going . If you have more experience you may wish to batches

<img src="./IMAGES/step2_component.jpg" width="30%">

There is one of these, marked R7 on the board
The colour code on each resistor shows: BROWN-BLACK-BROWN-GOLD

## Step 4: 470R Resistor

<img src="./IMAGES/step3_component.jpg" width="30%">

There are 3 of these, marked R2, R3 and R4 on the board
The colour code on each resistor shows: YELLOW-PURPLE-BROWN
Orientation does not matter, it can be soldered either way round

## Step 5: 2k Resistor

<img src="./IMAGES/step4_component.jpg" width="30%">

There are 4 of these, marked R1, R5, R6 and R8 on the board
The colour code on each resistor shows: RED-BLACK-RED-GOLD
Orientation does not matter, it can be soldered either way round

## Step 6: 1N4148 Diode

<img src="./IMAGES/step5_component.jpg" width="30%">

There is just one of these, marked D1 on the board.

Orientation here _does_ matter, the black line on the diode should align with
- the white line
- where the K is printed
- the square pad

## Step 7: 100nF Cermamic Capacitor

<img src="./IMAGES/step6_component.jpg" width="30%">

There is just one of these, marked C1 on the board
It can be identified by the number 104 printed on it

## Step 8: 2N3904 Transistor

<img src="./IMAGES/step7_component.jpg" width="30%">

There is just one of these, marked T1 on the board
N-P-N 

## Step 9: 5mm Red LED

<img src="./IMAGES/step8_component.jpg" width="30%">

There is just one of these, marked PWR_LED1 on the board
Orientation here _does_ matter, the longest leg should go through the round pad (closest to the side marked A)

## Step 10: Speaker

<img src="./IMAGES/step9_component.jpg" width="30%">

There is just one of these, marked SPK1 on the board

## Step 11: 2-pin Programming Header

<img src="./IMAGES/step10_component.jpg" width="30%">

There is just one of these, marked PGM/DBG1 on the board

## Step 12: PS2 Keyboard Connector

<img src="./IMAGES/step11_component.jpg" width="30%">

There is just one of these, marked PS2_KBD1 on the board

## Step 13: VGA Connector

<img src="./IMAGES/step12_component.jpg" width="30%">

There is just one of these, marked VGA1  on the board

## Step 14: Power Jack Connector

<img src="./IMAGES/step13_component.jpg" width="30%">

There is just one of these, marked PWR_JACK1 on the board
# Programming using Raspberry Pi Pico

You will need a Raspberry Pi with pin headers. We used a (Pico 1)[https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html#pico-1-technical-specification]



<img src="./IMAGES/pico_programmer.jpg" width="30%">

## Step 15: 

very important - without this you will see nothing

## Testing

Once your 