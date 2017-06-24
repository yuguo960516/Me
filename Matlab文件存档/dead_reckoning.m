V=diag([0.02,0.5*pi/180].^2);
veh=Vehicle(V);
veh.add_driver(RandomPath(10));
P0=diag([0.005,0.005,0.001].^2);
ekf=EKF(veh,V,P0);
ekf.run(1000);
figure(1);
veh.plot_xy();
hold on;
ekf.plot_xy('r');
hold on;
ekf.plot_ellipse([],'g');
figure(2);
ekf.plot_P();

