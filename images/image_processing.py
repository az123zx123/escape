import os


CMD = r'D:\ImageMagick\convert.exe'
SOURCE_PATH = r'e:\srgb'


def doStrip(path):
  data = {};
  print(path)
  for root, dirs, files in os.walk(path):
    for file in files:
      name = file.lower();
      if name.find('.png') != -1:
        path = os.path.join(root, file)
        #print('"{0}" {1} -strip {1}'.format(CMD, path, path))
        #os.system('"{0}" {1} -strip {1}'.format(CMD, path, path));
        #print('"{0}" {1} -profile "sRGB_v4_ICC_preference.icc" {1}'.format(CMD, path, path))
        os.system('"{0}" {1} -profile sRGB_v4_ICC_preference.icc {1}'.format(CMD, path, path));



doStrip(SOURCE_PATH)
