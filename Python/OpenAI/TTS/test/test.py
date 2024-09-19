from pathlib import Path
from openai import OpenAI
client = OpenAI(api_key='sk-proj-AfB9WRqErUOAOXLUjzupT3BlbkFJ67hsSD9SXE8y8jgoFktZ')

speech_file_path = Path(__file__).parent / "audio.mp3"
with open('text.txt', 'r', encoding='utf-8') as file:
    lines = file.read()

with client.audio.speech.with_streaming_response.create(
  model="tts-1",
  voice="shimmer",
  input=lines
) as response:
    response.stream_to_file(speech_file_path)