import serial
import requests

ser = serial.Serial('COM3', 9600, timeout=1)
ser.flush()

url = "http://thingsboard.cloud/api/v1/2A2r5DTI6N1J3x3I8Pmp/telemetry"

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        print(line)

        if "Movimento detectado!" in line:
            data = {'motion': True}
        elif "Movimento parado!" in line:
            data = {'motion': False}
        else:
            continue

        try:
            response = requests.post(url, json=data)
            print(f"Dados enviados: {data} - Status Code: {response.status_code}")
        except requests.exceptions.RequestException as e:
            print(f"Erro ao enviar dados: {e}")
