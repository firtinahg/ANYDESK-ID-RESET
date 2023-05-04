import os 
import tkinter
import psutil
import tkinter


class Anydesk:
    def __init__(self) -> None:
        ...
        
    def find_conf_file(self):
        disknames = ['A:\\','B:\\','C:\\','D:\\','E:\\','F:\\','H:\\','G:\\','I:\\','J:\\','K:\\','L:\\','M:\\','N:\\']
        location_of_service_conf = "ProgramData\\AnyDesk\\service.conf"
        LOC = ""

        for diskname in disknames:
            LOC = diskname + location_of_service_conf
            if os.path.exists(LOC):
                print("service.conf file found at-> ",diskname)
                break
            else:
                LOC = None

        return LOC
    
    def remove_conf_file(self,loc_of_file):
        os.remove(loc_of_file)

    def kill_open_anydesk_exes(self):
        for process in psutil.process_iter():
            if process.name().startswith("AnyDesk"):
                process.kill()

    def reset_ID(self):
        loc_of_conf_file =  self.find_conf_file()
        if loc_of_conf_file is not None:
            self.remove_conf_file(loc_of_conf_file)
            self.kill_open_anydesk_exes()
            print("ID resetted successfully!")
            return
        print( "CAN'T FIND service.conf FILE IN DISK!" )
        print( "Please try to open AnyDesk and see the ID, then re-run the program!" )


anydesk = Anydesk()
anydesk.reset_ID()



