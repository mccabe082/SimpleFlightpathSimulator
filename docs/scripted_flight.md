# Simple Target Simulation Proposal

## Basic Outline
The document outlines a simplified approach for simulating the motion of radar targets.  The *state* of a target is represented by a single point in a *state space*, $\bar{X}$ which efines the position and orientation of the target:

$$
\bar{X}(t) = 
[
 x(t),
 y(t),
 z(t),
 \theta(t),
 \phi(t),
 \psi(t),
 \dot{x}(t),
 \dot{y}(t),
 \dot{z}(t),
 \dot{\theta}(t),
 \dot{\phi}(t),
 \dot{\psi}(t)]^T
$$

Symbol | Description
---    | ---
$x, y, z$ | x, y position and altitude respectively
$\theta, \phi, \psi$ | roll, pitch and yaw respectively
$\dot{x}, \dot{y}, \dot{z}$ | target velocity
$\dot{\theta}, \dot{\phi}, \dot{\psi}$ | target's angular velocity

The target motion is calculated over a series of discrete time intervals.  Given an initial state $\bar{X}_{start}$ the final state $\bar{X}_{end}$ over a short time interval $\Delta t$ at is calculated using a simple *update* function $\bar{X}_{end} = f(\bar{X}_{start},\Delta t)$.  Different update functions, $f$ correspondig to different basic manovers.

## Basic Manouvers

Update rules are used to calculate the future target state of the aircraft, $\bar{X}_{target}(t+\delta t)$. All manouvers use update rules which are depend on the specific manouver...  There are a bunch of quantities which we might need to define or calculate and keep on hand when calculating update functions.  These are given below

Quantity | Symbol | Unit
--- | --- | ---
Acceleration due to gravity | $g=9.81$ |  $m\cdot s^{-1}$
Target Mass | $m$ | $kg$
Target Potential Energy | $E_p =mgz$ | $J$
Target Kinetic Energy | $E_k = \frac{1}{2}mV^2$ | $J$
Target Momentum | $P = mV$ | $kg\cdot m\cdot s^{-1}$
Target Speed | $V= norm (\dot{x},\dot{y},\dot{z})$ | $m\cdot s^{-1}$
Target Horizontal Speed | $V_{horizontal} = norm (\dot{x},\dot{y})$| $m\cdot s^{-1}$
Maximum change in abs pitch rate| $\ddot{\theta}_{max}$ | 
### Scripted Cruise
Control Rule | Notes
--- | --- 
$\dot{z}_{target} = 0$ | end climb or decent
$\theta_{target} = 0$ | straighten
$\phi_{target} = 0$ | level
$\psi_{target} = \psi(t_0)$ | maintain original heading

Kinematic Update Rule | Notes
--- | ---
$x(t_0+\delta t) = \frac{\dot{x}(t_0+\delta t)+ \dot{x}(t_0)}{2}\cdot\delta t$ |
$y(t_0+\delta t) = \frac{\dot{y}(t_0+\delta t)+ \dot{y}(t_0)}{2}\cdot\delta t$ | 
$z(t_0+\delta t) = \frac{\dot{z}(t_0+\delta t)+ \dot{z}(t_0)}{2}\cdot\delta t$ | 
$\theta(t_0+\delta t) = \frac{\dot{\theta}(t_0+\delta t)+ \dot{\theta}(t_0)}{2}\cdot\delta t$ |
$\phi(t_0+\delta t) = \frac{\dot{\phi}(t_0+\delta t)+ \dot{\phi}(t_0)}{2}\cdot\delta t$ | 
$\psi(t_0+\delta t) = \frac{\dot{\psi}(t_0+\delta t)+ \dot{\psi}(t_0)}{2}\cdot\delta t$ | 
$\dot{x}(t_0+\delta t) = \sqrt{\frac{V^2(t_0)-\dot{z}^2(t_0)}{1+(\frac{\dot{y}(t_0)}{\dot{x}(t_0)})^2}}$ | maintain kinetic energy
$\dot{y}(t_0+\delta t) = \frac{\dot{y}(t_0)}{\dot{x}(t_0)}\cdot \dot{x}(t_0+\delta t)$ | maintain heading
$\dot{z}(t_0+\delta t) =a_{z_{max}}\cdot\dot{z}_{target}+(1-a_{z_{max}})\cdot \dot{z}(t_0)$ | gently reduce climb or decent
$\dot{\theta}(t_0+\delta t) = min(\ddot{\theta}_{max}\cdot \delta t,\frac{\theta_{target}-\theta(t_0)}{\delta t})$ | expression doesn't consider negative rate of roll
$\dot{\phi}(t_0+\delta t) = min(\ddot{\phi}_{max}\cdot \delta t,\frac{\phi_{target}-\phi(t_0)}{\delta t})$ | expression doesn't consider negative rate of pitch
$\dot{\psi}(t_0+\delta t) = min(\ddot{\psi}_{max}\cdot \delta t,\frac{\psi_{target}-\psi(t_0)}{\delta t})$ | expression doesn't consider negative rate of yaw
|

### Scripted Climb/Decent
 TODO



