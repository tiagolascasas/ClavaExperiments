chmod 666 dotproduct -R
chmod 666 example_print -R
docker run -it \
	-v $HOME:$HOME \
	-v /tmp/.X11-unix:/tmp/.X11-unix \
	-v /media/:/media/ \
    -v /media/tls/bb85d90f-e2ee-425a-98fb-5dc0f287682c/tools/Xilinx/:/opt/xilinx/ \
    -v /media/tls/bb85d90f-e2ee-425a-98fb-5dc0f287682c/tools/Xilinx/Xilinx.lic:/home/ompss/Xilinx.lic \
    -v $(pwd)/dotproduct:/home/ompss/host_apps/dotproduct \
    -v $(pwd)/example_print:/home/ompss/host_apps/example_print \
	-e DISPLAY=$DISPLAY \
    -e PATH="/opt/xilinx/Vivado/2024.1/bin/:/opt/xilinx/Vitis_HLS/2024.1/bin/:$PATH" \
	--network host \
	ompss_2_at_fpga:unknwn bash

# -v /opt/petalinux/:/opt/petalinux/ \
