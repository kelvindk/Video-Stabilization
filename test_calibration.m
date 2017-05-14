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

%% extract data from captured video & gyro
% clear all;

video_file = '4';

[gyro frame_time] = import_video_data(video_file);
run ../vlfeat-0.9.20/toolbox/vl_setup.m

warning('off', 'Images:initSize:adjustingMag');

transformtype = 'projective';

% read corresponding movie
xyloObj = VideoReader([video_file '.mp4']);
display(xyloObj);

num_frames = xyloObj.NumberOfFrames;
vid_height = xyloObj.Height;
vid_width = xyloObj.Width;

base_frame = read(xyloObj, 1);
Ib = single(rgb2gray(base_frame)) / 255;
[fb, db] = vl_sift(Ib, 'PeakThresh', 0.02) ;

% W = struct('tform', {}, 'x1', {}, 'x2', {});
% 
% % Read one frame at a time.
% for f = 2:num_frames
%     frame = read(xyloObj, f);
%     
%     Ia = single(rgb2gray(frame)) / 255;
%     [fa, da] = vl_sift(Ia, 'PeakThresh', 0.01) ;
% %     imshow(frame);
% %     vl_plotframe(fa);
%     
%     [matches, scores] = vl_ubcmatch(da, db);
%     matches = matches(:, scores > median(scores));
% 
%     ma = fa(1:2,matches(1,:));
%     mb = fb(1:2,matches(2,:));
% 
% %     imshow([base_frame; frame]);
%     line([ma(1,:); mb(1,:)],[ma(2,:); mb(2,:) + 720],'Color','b');
%     
%     [tform, inlier_idx, best_error] = ransacfit(frame, base_frame, ma', mb', transformtype, 1, 50);
% 
% %     imshow([base_frame; frame]);
% %     line([ma(1,inlier_idx); mb(1,inlier_idx)],[ma(2,inlier_idx); mb(2,inlier_idx) + 720],'Color','b');
% %     pause(0.1);
%     
% %     imshow(imtransform(frame, tform, 'XData', [1 size(frame,2)], 'YData', [1 size(frame,1)]));
% %     hold on;
% %     h = imshow(base_frame);
% %     set(h, 'AlphaData', 0.6);
% %     pause(0.1);
% 
%     base_frame = frame;
%     fb = fa;
%     db = da;
%     W(f-1).tform = tform;
%     W(f-1).x1 = ma(:,inlier_idx)';
%     W(f-1).x2 = mb(:,inlier_idx)';
%     fprintf('num inliers: %d, error: %d, frame %d of %d\n', numel(inlier_idx), best_error, f, num_frames);
% end


[c t0 ts] = solve_affine(gyro, frame_time, W, video_file)

% [c t0 ts d err] = solve_affine_drift(gyro, frame_time, W, video_file);

% %% meshwarp
% clear meshwarpmex
% % load(['mat/camera_param_shake2.mat'], 'cp');
% % fl = cp(1);
% % td = cp(2);
% % ts = cp(3);
% 
% c = 380;
% td = 0;
% ts = 0;
% t0 = 0;
% 
% g = gyro(:,1:3);
% g(:,1) = -g(:,1);
% d = -mean(g,1);
% g = g + d(ones(size(g,1),1),:);
% 
% [dth, theta] = frame_rotations_non_lin(g, gyro(:,4), frame_time, t0, ts);
% 
% % read corresponding movie
% xyloObj = VideoReader([video_file '.mp4']);
% display(xyloObj);
%  
% num_frames = xyloObj.NumberOfFrames;
% vid_height = xyloObj.Height;
% vid_width = xyloObj.Width;
% 
% crop_amount = 50;
% 
% th = [0 0 0];
% w = vid_width / 2;
% h = vid_height / 2;
% M1 = [1 0 -w; 0 1 -h; 0 0 c];
% M2 = [1 0 w/c; 0 1 h/c; 0 0 1/c];
% 
% frame = read(xyloObj, 1);
% outvid = VideoWriter(['mat/' video_file '_registered_nonlin.avi']);
% open(outvid);
% mframe = vertcat(frame, frame);
% writeVideo(outvid, mframe);
% % writeVideo(outvid, cropim(frame, crop_amount, crop_amount));
% tic;
% % Read one frame at a time.
% for f = 1:num_frames-1
%     frame = read(xyloObj, f+1);
% %     imshow(warped);
% %     pause(0.1);
%     
%     th = th + dth(f,:);
%     
%     stabilized = gridwarp(frame, M1, M2, theta, gyro(:,4), frame_time(f) - t0, ts);
% %     imshow(stabilized);
% %     pause;
% 
%     mframe = vertcat(frame, stabilized);
%     imshow(mframe);
%     writeVideo(outvid, mframe);
% %     writeVideo(outvid, cropim(stabilized, crop_amount, crop_amount));
%     display([num2str(f+1) ' of ' num2str(num_frames)]);
% end
% toc;
% close(outvid);
