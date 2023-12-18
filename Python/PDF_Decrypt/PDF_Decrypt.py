import os
import PyPDF2

def decrypt_pdf(input_path, output_path, password):
    with open(input_path, 'rb') as file:
        reader = PyPDF2.PdfReader(file)
        
        if reader.is_encrypted:
            reader.decrypt(password)
            
            writer = PyPDF2.PdfWriter()
            for i in range(len(reader.pages)):
                writer.add_page(reader.pages[i])

            with open(output_path, 'wb') as outfile:
                writer.write(outfile)
            print(f"{input_path} has been decrypted and saved as {output_path}")
        else:
            print(f"{input_path} is not encrypted")

# 文件夹路径
directory = r'C:\Users\Xiaochen Chen\Downloads\TWK'

# PDF 密码
pdf_password = '2904'
output_dir = directory + r'\Decrypted'
if not os.path.exists(output_dir):
    os.mkdir(output_dir)
for filename in os.listdir(directory):
    if filename.endswith('.pdf'):
        input_file = os.path.join(directory, filename)
        output_file = os.path.join(output_dir, filename)      
        decrypt_pdf(input_file, output_file, pdf_password)
