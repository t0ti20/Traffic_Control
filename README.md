
# On-demand Traffic Light Control

Implement a traffic lights system with an on-demand crosswalk button

![App Screenshot](https://i.postimg.cc/LXHRJ9MS/Simulation-Proteus-8-Professional-Schematic-Capture-2022-09-07-21-59-17-Trim-00-00-00-00-00-30.gif)


## Breif

Crosswalk buttons let the signal operations know that someone is planning to cross the street, so the light adjusts, giving the pedestrian enough time to get across.

## Project 	Implementation 

This project is used by the following companies:

- System Design
  - 
    -	We have two main modes(normal-pedestrian).
    -	Normal Mode: Cars' LEDs will be changed every five seconds starting from Green then yellow(blinking) then red then yellow then Green.
    -	Pedestrian Mode: Change when the pedestrian button is pressed, so we have 3 cars traffic states.
        -	Red: The pedestrian's Green LED and the cars' Red LEDs will be on for five seconds.
        -	Green-Yellow: The pedestrian Red LED will be on, both Yellow LEDs start to blink for five seconds then Red LED and pedestrian Green LEDs are on for five seconds.
    - The cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
    - Pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.

- System Flow Chart
  -
   ![App Screenshot](https://i.postimg.cc/TPkL2HZt/image.png)


- Prepare your development environment
  - 
    | 1-APPLICATION | 2-HAL | 3-MCAL | 4-LIBRARY |
    | :---: | :---: | :---: | :---: |

- Modules & Drivers
  -
    -	[Led Module (HAL)](https://github.com/t0ti20/Traffic_Control/tree/master/Project/HAL).
    -	[Button Module (HAL)](https://github.com/t0ti20/Traffic_Control/tree/master/Project/HAL/Button).
    -	[Timer Driver (MCAL)](https://github.com/t0ti20/Traffic_Control/tree/master/Project/MCAL/Timer).
    -	[DIO Driver (MCAL)](https://github.com/t0ti20/Traffic_Control/tree/master/Project/MCAL/DIO).
    -	[External Interrupt (MCAL)](https://github.com/t0ti20/Traffic_Control/tree/master/Project/MCAL/External_Interrupt).

- Test Application
  -
https://user-images.githubusercontent.com/61616031/188972881-775745bf-b199-419c-a7a2-247273ad6b32.mp4
## Authors

- [@Khaled El_Sayed](https://github.com/t0ti20)
