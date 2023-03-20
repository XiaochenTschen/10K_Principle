from tkinter import Tk     # from tkinter import Tk for Python 3.x
from tkinter.filedialog import askopenfilename

Tk().withdraw() # we don't want a full GUI, so keep the root window from appearing
filename = askopenfilename() # show an "Open" dialog box and return the path to the selected file
print(filename)
'''
import fitz # install using: pip install PyMuPDF

with fitz.open(filename) as doc:
    text = ""
    for page in doc:
        text += page.get_text()

print(text)
'''
import tabula

df = tabula.read_pdf(filename, encoding='gbk', pages='all')
print(df)