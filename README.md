# Tech Fusion Cruiser

#### This project involves the creation of a Bluetooth-controlled car, which demonstrates the integration of various electronic components and modules to achieve wireless control. The car is designed to be operated via Bluetooth, leveraging the HC-05 Bluetooth module for wireless communication. The core of the project is the Aries development board, which is used to execute the control code and manage the car's operations.

#### For motor control, the L298N motor driver is employed, enabling precise control of the four DC motors that power the car's movement. The entire setup is powered by a portable power bank, providing the necessary electrical power to all components. This project exemplifies a practical application of Bluetooth technology in remote vehicle control, making use of microcontroller programming, motor control, and wireless communication.

## Components used
<table>
  <thead>
    <th>Sl No</th>
    <th>Components</th>
  </thead>
  <tbody>
    <tr>
      <td>01</td>
      <td>ARIES v3.0 Development Board</td>
    </tr>
    <tr>
      <td>02</td>
      <td>HC-05 Bluetooth Module</td>
    </tr>
    <tr>
      <td>03</td>
      <td>L298N Motor Driver</td>
    </tr>
    <tr>
      <td>04</td>
      <td>Power bank/Batteries</td>
    </tr>
    <tr>
      <td>05</td>
      <td>Chassis with 4 DC Motors</td>
    </tr>
  </tbody>
</table>

#### 01. ARIES v3.0 Development Board
<!--![aries_V3](https://images.mobilism.org/?di=R8PK)-->
#### 02. HC-05 Bluetooth Module
#### 03. L298N Motor Driver
#### 04. DC Motors x 4
#### 05. Power bank/Batteries
#### 06. Chassis


## Connections
### HC05 and Aries Board
<table>
  <thead>
    <th>HC05</th>
    <th>Aries Board</th>
  </thead>
  <tbody>
    <tr>
      <td>12V & 5V</td>
      <td>5V</td>
    </tr>
    <tr>
      <td>GND</td>
      <td>GND</td>
    </tr>
    <tr>
      <td>RXD</td>
      <td>TX1</td>
    </tr>
    <tr>
      <td>TXD</td>
      <td>RX1</td>
    </tr>
  </tbody>
</table>

### L298N Motor Driver and Aries Board
<table>
  <thead>
    <th>L298N</th>
    <th>Aries Board</th>
  </thead>
  <tbody>
    <tr>
      <td>VCC</td>
      <td>5V</td>
    </tr>
    <tr>
      <td>5V In/Out</td>
      <td>VIN</td>
    </tr>
    <tr>
      <td>GND</td>
      <td>GND</td>
    </tr>
    <tr>
      <td>ENA</td>
      <td>PWM1</td>
    </tr>
    <tr>
      <td>IN1</td>
      <td>GPIO13</td>
    </tr>
    <tr>
      <td>IN2</td>
      <td>GPIO15</td>
    </tr>
    <tr>
      <td>IN3</td>
      <td>GPIO14</td>
    </tr>
    <tr>
      <td>IN4</td>
      <td>GPIO16</td>
    </tr>
    <tr>
      <td>ENB</td>
      <td>PWM2</td>
    </tr>
  </tbody>
</table>

### L298N and Motors
<table>
  <thead>
    <th>L298N</th>
    <th>Motors</th>
  </thead>
  <tbody>
    <tr>
      <td>Motor Terminal 01</td>
      <td>Front and Rear Left Motors</td>
    </tr>
    <tr>
      <td>Motor Terminal 02</td>
      <td>Front and Rear Left Motors</td>
    </tr>
    <tr>
      <td>Motor Terminal 03</td>
      <td>Front and Rear Right Motors</td>
    </tr>
    <tr>
      <td>Motor Terminal 04</td>
      <td>Front and Rear Right Motors</td>
    </tr>
  </tbody>
</table>


<!--![image](https://github.com/bhatbharath/cdac_vega_tech_fusion_cruiser/assets/120124748/751995a9-3deb-4854-bacb-8a84311aa769)
![image](https://github.com/bhatbharath/cdac_vega_tech_fusion_cruiser/assets/120124748/dd992305-dd95-4b4c-8cdc-3d214d0a7362)
![image](https://github.com/bhatbharath/cdac_vega_tech_fusion_cruiser/assets/120124748/68771b9a-054e-4936-a06c-0e807815d303)-->




### You can access the report from the below link attached
[Report.pdf](https://github.com/user-attachments/files/15751054/cdac_tech_fusion_cruiser.pdf)
