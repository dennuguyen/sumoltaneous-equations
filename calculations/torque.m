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



%}

m = 2; % (kg); mass of both bots
N = m * 9.81; % (N)
F_f = 1.15 * N; % (N); 1.15 is rubber on rubber
r = 0.065; % (m)
tau = r * F_f; % (Nm)
