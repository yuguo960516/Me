map=Map(20);
V=diag([0.1,0.1*pi/180].^2);
veh=Vehicle(V);
veh.add_driver(RandomPath(10));
W=diag([0.005,0.5*pi/180]);
sensor=RangeBearingSensor(veh,map,W);
Q=diag([0.1,0.1,1*pi/180]);
L=diag([0.1,0.1]);
pf=ParticleFilter(veh,sensor,Q,L,1000);
pf.run(1000);

