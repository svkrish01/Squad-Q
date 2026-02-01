import time
from arduino.app_utils import App, Bridge
from arduino.app_bricks.audio_classification import AudioClassification

curr_cmd = 0
cmd_time = 0

def current_cmd(command, speed):
    global curr_cmd, cmd_time
    t1 = time.time()
    if (curr_cmd != command) and (t1 - cmd_time > 1):
        control_motors(command, speed)
        curr_cmd = command
        cmd_time = time.time()


def control_motors(command, speed):
    if command == 1:
        Bridge.call("control_motors", command, speed)
   #     time.sleep(1)
        Bridge.call("control_motors", 0, 0)

    elif command == 2:
        Bridge.call("control_motors", command, speed)
   #     time.sleep(1)
        Bridge.call("control_motors", 0, 0)

    elif command == 3:
        Bridge.call("control_motors", command, speed)
   #     time.sleep(0.5)
        Bridge.call("control_motors", 0, 0)

    elif command == 4:
        Bridge.call("control_motors", command, speed)
        time.sleep(0.5)
        Bridge.call("control_motors", 0, 0)


classifier = AudioClassification(confidence=0.8)

classifier.on_detect("front", lambda: current_cmd(1, 100))
classifier.on_detect("back", lambda: current_cmd(2, 100))
classifier.on_detect("left", lambda: current_cmd(3, 100))
classifier.on_detect("right", lambda: current_cmd(4, 100))

print("Hello world!")

App.run()
