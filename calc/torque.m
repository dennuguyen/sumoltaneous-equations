%{

Calculating required torque.

%}

%% Variables

syms m; % sumobot mass (kg)
syms a; % sumobot acceleration (m/s^2)
syms mu; % coefficient of static friction
syms N; % normal force (N)
syms F_f; % friction force (N)
syms tau; % motor torque (Nm)
syms r; % wheel radius (m)


%% Equations

eqn1 = N == m * 9.81; % (N)
eqn2 = F_f == mu * N; % (N)
eqn3 = tau == r * F_f; % (Nm)

%% Torque Calculation

%{

Bare minimum torque of rubber wheel on rubber ground.

%}

m = 1; % (kg)
N = m * 9.81; % (N)
F_f = 1.15 * N; % (N); 1.15 is rubber on rubber
r = 0.065; % (m)
tau_1 = r * F_f; % (Nm)

%% Torque Calculation

%{

Bare minimum torque to overcome opponent.

%}

tau_opp = 0.04903325; % (Nm); from https://www.createunsw.com.au/store/Tiny-metallic-DC-motor/
tau_2 = tau_1 + tau_opp; % (Nm)
