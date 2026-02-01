import time
from arduino.app_utils import App, Bridge
from arduino.app_bricks.audio_classification import AudioClassification

def control_motors(command, speed):
  Bridge.call("control_motors", command, speed)
  time.sleep(2)
  Bridge.call("control_motors", 0, 0)

classifier = AudioClassification(confidence = 0.5)
classifier.on_detect("front", lambda: control_motors(1, 100))
classifier.on_detect("back", lambda: control_motors(2, 100))
classifier.on_detect("left", lambda: control_motors(3, 100))
classifier.on_detect("right", lambda: control_motors(4, 100))

print("Hello world!")

App.run()