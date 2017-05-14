% Digital Video Stabilization and Rolling Shutter Correction using Gyroscopes
% Copyright (C) 2011 Alexandre Karpenko
% 
% This program is free software: you can redistribute it and/or modify
% it under the terms of the GNU General Public License as published by
% the Free Software Foundation, either version 3 of the License, or
% any later version.
% 
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details.
% 
% You should have received a copy of the GNU General Public License
% along with this program.  If not, see <http://www.gnu.org/licenses/>.
clear all;

video_file = '9';

[gyro frame_time] = import_video_data(video_file);
run ./vlfeat-0.9.20/toolbox/vl_setup.m

warning('off', 'Images:initSize:adjustingMag');

%% meshwarp
clear meshwarpmex
% load(['mat/camera_param_shake2.mat'], 'cp');
% fl = cp(1);
% td = cp(2);
% ts = cp(3);

% 4
% fl = 364.918349;
% td = 0.001181;
% ts = -0.002740;f

fl = 715.032453;
td = -0.009055;
ts = 0.004764;

g = gyro(:,1:3);

sigma2 = 4000;
gauss = exp(-(-120:120).^2 / sigma2);
gauss = gauss ./ sum(gauss);
% g(:,1) = g(:,1) - conv(gyro(:,1), gauss, 'same');
% g(:,2) = g(:,2) - conv(gyro(:,2), gauss, 'same');
% g(:,3) = g(:,3) - conv(gyro(:,3), gauss, 'same');
dgt = diff(gyro(:,4)); % interval between each gyro sample
theta1 = ((g(1:end-1,:) + g(2:end,:)) / 2) .* dgt(:,[1 1 1]);
theta1 = [0 0 0; cumsum(theta1, 1)];
dth = diff(interp1(gyro(:,4) - td, theta1, frame_time, 'linear', 'extrap'));

theta2 = ((gyro(1:end-1,1:3) + gyro(2:end,1:3)) / 2) .* dgt(:,[1 1 1]);
theta2 = [0 0 0; cumsum(theta2, 1)];

% read corresponding movie
xyloObj = VideoReader([video_file '.mp4']);
display(xyloObj);
 
num_frames = xyloObj.NumberOfFrames;
vid_height = xyloObj.Height;
vid_width = xyloObj.Width;

crop_amount = 50;

frame = read(xyloObj, 1);
outvid = VideoWriter(['mat/' video_file '_meshwarp_large.avi']);
open(outvid);
mframe = vertcat(frame, frame);
writeVideo(outvid, mframe);
% writeVideo(outvid, cropim(frame, crop_amount, crop_amount));

% Read one frame at a time.
for f = 1:num_frames-1
% for f = 1:1
    frame = read(xyloObj, f+1);
%     imshow(frame);
%     pause(0.1);
    
    stabilized = meshwarp(frame, dth(f,:), theta2, gyro(:,4), frame_time(f+1), td, ts, fl);
%     imshow([frame; stabilized]);
%      imshow(stabilized);
%      pause(0.1);

%     writeVideo(outvid, cropim(stabilized, crop_amount, crop_amount));
    mframe = vertcat(frame, stabilized);
    imshow(mframe);
    writeVideo(outvid, mframe);
    display([num2str(f+1) ' of ' num2str(num_frames)]);
end

close(outvid);