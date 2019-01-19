# Wheelchair Controlled by Brain Signal
 
wheelchair aims disabled people in which they can move using EEG signals from Emotiv

## Motivation

The 2013 [WHO](https://www.who.int/) report states that there is 1 billion human being facing some sort of disability
issue worldwide.

There are more than 140 million paralyzed people around the world (2% of population).

The project is a wheelchair aiming disabled people in which they can move using neuro-signals transmitted by the brain
while thinking of a particular movement (EEG), using Brain Computer Interface (BCI) technology. While thinking, 
the brain produces electrical pulses in the neurons, the sensor then intercepts these signals and transfers it to 
the computer to process it, sending it to the chair controller that orders machine movement. The chair also operates 
automatically in case of the existence of a barrier in its movement path.

## Brain-Computer Interface (BCI)

A direct communication pathway between an enhanced or wired brain and an external device. 
BCI differs from neuromodulation in that it allows for bidirectional information flow. 
BCIs are often directed at researching, mapping, assisting, augmenting, or repairing human cognitive or sensory-motor 
functions.

## Emotiv epoc

EEG signals sensor, produced by [emotiv](https://emotiv.com), 14 channel mobile EEG

![emotiv](https://github.com/montaserFath/Wheelchair-controlled-by-Brain-Signal/blob/master/images/emotiv.png)


# How it works?

There are three components:

- EEG signals capturing and processing (Emotiv epoc sensor, Neural Network for processing EEG).

- Communication (Input: Neural Network output, Output Signals to Wheelchair controller).

- Wheelchair controller (Ardunio, Ultrasonics sensors, Servo motors, DC motors and Bluetooth module).


![all](https://github.com/montaserFath/Wheelchair-controlled-by-Brain-Signal/blob/master/images/bci.png)

# Results

The BCI chair for disabled people project was executed, with signal accuracy of 74.24% and 83.33% for cognitive (thinking) signals and facial expression signals, respectively. This accuracy is appropriate for electronic gaming, educational and showcase systems, nevertheless this accuracy is subject to enhancement and further research to serve for optimization of a project which needs maximum accuracy.

# Prizes

- Patent number (4254) Sudan 

- [AUDIENCE AWARD Falling Walls Lab Finals 2017](https://falling-walls.com/lab/young-innovators-of-the-year-2017/winner2017-montaser-mohammedalamen)

- First prize at Creative Students Forum (Association of Arab Universities), Egypt.

- Undergraduate research prize University of Khartoum, Sudan

# Media

- [Falling Walls Lab Berlin](https://youtu.be/ZpqypVq8Qgo)

- [Blue Nile Interview](https://youtu.be/dvuIe8c-Xac)

- [Tenchologya Interview](https://www.youtube.com/watch?v=LN_7vt4fjq4&t=7s)

# Installation 


# References

- [Wikipedia](https://en.wikipedia.org/wiki/Brain%E2%80%93computer_interface)
 
