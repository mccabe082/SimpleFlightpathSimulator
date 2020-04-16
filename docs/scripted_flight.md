# Scripted Flight

## State Vector
$
\begin{pmatrix}
 v_{total} \\
 \theta \\
 \phi \\
 \psi \\
 P \\
 Q \\
 R \\
 x \\
 y \\
 z 
\end{pmatrix}
$

## Scripted Cruise
$$
\begin{pmatrix}
 a_{total} \\
 \dot{\theta} \\
 \dot{\phi} \\
 \dot{\psi} \\
 \dot{P} \\
 \dot{Q} \\
 \dot{R} \\
 v_x \\
 v_y \\
 v_z 
\end{pmatrix}
=
\begin{pmatrix}
 \sqrt{v_x^2+v_y^2+v_z^2} \\
 0 \\
 0 \\
 arctan2{(\tfrac{v_{x_{target}}}{v_{y_{target}}})} \\
 0 \\
 0 \\
 0 \\
 v_{x_{target}} \\
 v_{y_{target}} \\
 0 
\end{pmatrix}
$$
### 1. Level Wings & Eliminate Roll:
$$
\begin{pmatrix}
 a_{total} \\
 \dot{\theta} \\
 \dot{\phi} \\
 \dot{\psi} \\
 \dot{P} \\
 \dot{Q} \\
 \dot{R} \\
 v_x \\
 v_y \\
 v_z 
\end{pmatrix}
=
\begin{pmatrix}
 \sqrt{v_x^2+v_y^2+v_z^2} \\
 P \\
 |\phi|>Q_{max}\cdot t?Q_{max}: 0       \\
 arctan2{(\tfrac{v_{x_{target}}}{v_{y_{target}}})} \\
 0 \\
 0 \\
 0 \\
 v_{x_{target}} \\
 v_{y_{target}} \\
 0 
\end{pmatrix}
$$

Want to
1. level the wings & eliminate roll:
   - $\dot{\phi}=|Q_{max}|*t_{min}(0-\phi)$
2. level nose & eliminate pitch:

3. Hold azimouth