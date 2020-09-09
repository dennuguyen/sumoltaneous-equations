%{

Calculating required battery or motor specifications.

%}

%% Variables

syms k_i; % rotor inertia (kgm^2)
syms k_t; % torque constant (Nm/A)
syms V_s; % voltage source (V)
syms V_emf; % back EMF (V)
syms R; % motor electrical resistance (Ohm)
syms I; % current (A)
syms w; % motor rpm (rad/s)
syms tau; % torque (Nm)
syms P_e; % electrical power (W)
syms P_m; % mechanical power (W)


%% Equations

eqn1 = V_emf == k_i * w;
eqn2 = I == (V_s - V_emf) / R;
eqn3 = tau == k_t * I;
eqn4 = P_e == V_s * I;
eqn5 = P_m == tau * w;

%% Battery Selection

%{

Given motor specifications we can select a battery.

Make sure to check the stall torque and stall current.

%}

% Known Variables
R = 2.68; % (Ohm)
k_i = 0.00000212; % (kgm^2)
k_t = 0.0429; % (Nm/A)
tau = 0.0523; % (Nm)

% Unknown Variables
I = tau / k_t; % (A)
w_1(V_s) = (V_s - I * R) / k_i; % (rad/s)
w_2(V_s) = V_s * I / tau; % (rad/s)

V_s = eval(solve(w_1 == w_2, V_s)); % (V)


%% Motor Selection

%{

Given battery specifications we can select a motor.

%}
