# Practice4LIN_ESE3810A
LIN Protocol (Master-Slave's)
**Practice Statement**

Implement a driver that provides Master and/or Slave functionality in a LIN protocol network, based on your K64 board.

You may use the UART driver included in the SDK.

The driver should provide an initialization function.

As a Master:

- The driver should offer a function to send "Message Frames" with different IDs.
- The result of the transaction should be provided via a callback function.
- The driver must implement the LIN Header as specified in the presentation. This means it should send the following elements: Synch Break, Synk, ID with ID bits, Length control, and parity bits.
- The driver should wait for the response and report it to the application task via a callback.

As a Slave:

- The driver should wait for the Header and check that the Synk Break, Synk, and parity bits are correct.
- If the ID corresponds to one of the messages assigned to this slave, it should call an application layer callback before responding to the message.
- The driver should implement the response as specified in the presentation, which means sending the following elements:
  - Data fields.
  - Calculate Checksum.
 
Each team must form a network of 3 nodes, with the messages transmitted over the network defined by each team.

![Lin_Image](https://github.com/user-attachments/assets/2271f9a0-4d07-47ab-90cf-6c1b19446028)
