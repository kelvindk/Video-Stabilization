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
run ./vlfeat-0.9.20/toolbox/vl_setup.m

warning('off', 'Images:initSize:adjustingMag');

transformtype = 'projective';

% read corresponding movie
xyloObj = VideoReader([video_file '.mp4']);
display(xyloObj);

% num_frames = xyloObj.NumberOfFrames;
% vid_height = xyloObj.Height;
% vid_width = xyloObj.Width;
% 
% base_frame = read(xyloObj, 1);
% Ib = single(rgb2gray(base_frame)) / 255;
% [fb, db] = vl_sift(Ib, 'PeakThresh', 0.02) ;
% 
% W = struct('tform', {}, 'x1', {}, 'x2', {});
% 
% % Read one frame at a time.
% for f = 2:num_frames
%     frame = read(xyloObj, f);
%     
%     Ia = single(rgb2gray(frame)) / 255;
%     [fa, da] = vl_sift(Ia, 'PeakThresh', 0.01) ;
%     
%     [matches, scores] = vl_ubcmatch(da, db);
%     matches = matches(:, scores > median(scores));
% 
%     ma = fa(1:2,matches(1,:));
%     mb = fb(1:2,matches(2,:));
% 
%     line([ma(1,:); mb(1,:)],[ma(2,:); mb(2,:) + 720],'Color','b');
%     
%     [tform, inlier_idx, best_error] = ransacfit(frame, base_frame, ma', mb', transformtype, 1, 50);
% 
%     base_frame = frame;
%     fb = fa;
%     db = da;
%     W(f-1).tform = tform;
%     W(f-1).x1 = ma(:,inlier_idx)';
%     W(f-1).x2 = mb(:,inlier_idx)';
%     fprintf('num inliers: %d, error: %d, frame %d of %d\n', numel(inlier_idx), best_error, f, num_frames);
% end

% W for video 4
load('4all.mat');

% Solve the trhee parameters
[fl td ts] = solve_affine(gyro, frame_time, W, video_file)
