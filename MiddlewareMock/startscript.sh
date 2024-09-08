#!/bin/bash

sleep 2&
exec taskset 1 ./sender1&
exec taskset 2 ./receiversender1 &
exec taskset 3 ./receiversender2 &
exec taskset 4 ./receiver1 &