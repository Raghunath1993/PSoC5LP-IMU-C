/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <IMUregister.h>
uint8 add_a =0x1d;
uint8 add_m =0x1e;
uint8 data_trans[10];
uint8 data_trans2[10];
uint8 data_receive[10];
int previous_data=0;
uint16 y_m_p=0;
uint16 x_m_p=0;
#define gyro_offset 31;
uint16 modes=6;
uint16 gyro_ana_ref= 1371;
uint16 gyro_dig_ref= 22590;
void clear_LCD_line2();
void initialize_acc();
void complete_transfer_acc();
void complete_transfer_mag();
void lcd_initalize();
void delay_surplus();
void stepper_motor_test();
void move_forward(int);
void move_backward(int);
void stepper_gyro(int);
void initialize_mag();
void mag_lcd(uint16,uint16,uint16);
void acc_final();
void mag_final();
void mag_app();
void acc_app();
void gyro_app();
void LCD_menu();
void lcd_matlab_acc();
void lcd_matlab_mag();
void lcd_matlab_gyro();
void matlab_display_mag();
void matlab_display_acc();
void histogram_display();
int main()
{
     CyGlobalIntEnable; /* Enable global interrupts. */
     int counter=0;
     I2C_Start();
     Opamp_Start();
     ADC_Start();
     ADC_StartConvert();
     LCD_Start();
     UART_Start();
     DAC_Start();
     //I2C_Enable();
     //I2C_DisableInt();
     
     initialize_acc();
     CyDelay(1000);
     initialize_mag();
     while(1)
     {
            //acc_final();
        
            switch(counter){
            case 0:
                LCD_menu();
                break;
            case 1:
                lcd_initalize();
                acc_final();
                break;
            case 2:
                mag_app();
                break;
            case 3:
                gyro_app();
                break;
            case 4:
                lcd_matlab_acc();
                matlab_display_acc();
                break;
            case 5:
                lcd_matlab_mag();
                matlab_display_mag();
            case 6:
                lcd_matlab_gyro();
                histogram_display();
                break;
            default:
                LCD_menu();
            
            }
            
        if(switch3_Read() == 0){
                 CyDelay(1000);
                 counter= counter+1;
                 if(counter > modes){
                    counter=0;
                 }
        }
             
    }    //stepper_motor_test();
       
    
  
}
 
void histogram_display(){
        int gyro_ana;
        int gyro_dig;
        uint8 dummy=0;
      
        
        gyro_dig=ADC_GetResult32();
        //gyro_dig= gyro_dig - gyro_offset;  
        gyro_ana=ADC_CountsTo_mVolts(gyro_dig); 
        gyro_ana= gyro_ana-1350;
        DAC_SetValue((dummy++));
        CyDelay(100);

}




void matlab_display_acc(){
    
        uint8 transfer[7];
        uint8 x_low=data_receive[0];
        uint8 x_high=0x22;
        uint8 y_low=0x23;
        uint8 y_high=0x24;
        uint8 z_low=0x25;
        uint8 z_high=0x26;
        data_receive[6]=0x0a;
        
        uint16 x_a;
        uint16 y_a;
        uint16 z_a;
        int i ;
        
        data_trans2[0]=0x28;
        I2C_MasterWriteBuf(add_a,data_trans2,0x01,I2C_MODE_COMPLETE_XFER); 
        for(i=0;i<10000;i++){ 
        }
        I2C_MasterReadBuf(add_a,data_receive,0x06,I2C_MODE_COMPLETE_XFER);
        for(i=0;i<10000;i++){    
        }
        transfer[0]=x_low;
        transfer[1]=x_high;
        transfer[2]=y_low;
        transfer[3]=y_high;
        transfer[4]=z_low;
        transfer[5]=z_high;
        transfer[6]=0x0A;
        x_a= x_high*256 + x_low;
        y_a= y_high*256 + y_low;
        z_a= z_high*256 + z_low;
        LCD_Position(1,0);
        LCD_PrintNumber(x_a);
        //UART_Start();
        UART_PutChar(0x22);
        UART_PutChar (0x0a);
        CyDelay(100);
        //UART_Stop(); 
      
}

void matlab_display_mag(){
        
        uint8 x_low=data_receive[0];
        uint8 x_high=data_receive[1];
        uint8 y_low=data_receive[2];
        uint8 y_high=data_receive[3];
        uint8 z_low=data_receive[4];
        uint8 z_high=data_receive[5];
        uint16 x_m;
        uint16 y_m;
        uint16 z_m;
        int i ;
        for(i=0;i<10000;i++){ 
        }
        data_trans2[0]=0x28;
        I2C_MasterWriteBuf(add_m,data_trans2,0x01,I2C_MODE_COMPLETE_XFER); 
        for(i=0;i<10000;i++){ 
        }
        
        I2C_MasterReadBuf(add_m,data_receive,0x06,I2C_MODE_COMPLETE_XFER);
        for(i=0;i<10000;i++){    
        }
        
        x_m= x_high*256 + x_low;
        y_m= y_high*256 + y_low;
        z_m= z_high*256 + z_low;
        UART_PutArray(data_receive,6);
    
    
}



void LCD_menu(){
    LCD_Position(0,1);
    LCD_PrintString("1.ACC");
    LCD_Position(0,6);
    LCD_PrintString("2.MAG");
    LCD_Position(0,12);
    LCD_PrintString("3.GY");
    LCD_Position(1,0);
    LCD_PrintString("SW2 CHANGE MODE");
       
    }



void mag_app()
{
    //initialize_mag();
    mag_final();
}

void gyro_app()
{
        int gyro_ana;
        int gyro_dig;
        int gyro_hig=0;
        int gyro_low=gyro_ana_ref;
        int rot_angle=0;
        int rotation_bit=0;
        int diff;
        int gyro_ana_diff;
        int gyro_ana_pre=0;
        int gyro_ana_n,gyro_ana_n1,gyro_ana_filt;
        gyro_dig=ADC_GetResult32();
        //gyro_dig= gyro_dig - gyro_offset; 
        gyro_ana_n1= gyro_ana;
        gyro_ana=ADC_CountsTo_mVolts(gyro_dig);
        /*
        LCD_Position(0,1);
        LCD_PrintNumber(gyro_dig);
        LCD_Position(1,0);
        LCD_PrintNumber(gyro_ana);
        */
        gyro_ana_filt= ((7*(gyro_ana_n1)+gyro_ana)/8);    // Filter the result
        diff=abs(gyro_ana_ref-gyro_ana_filt);
        
        
        if(diff>10){
            LCD_ClearDisplay();
            while ((gyro_ana<(gyro_ana_ref-3))||(gyro_ana>(gyro_ana_ref + 3))){
                 gyro_dig=ADC_GetResult32();
                 gyro_ana=ADC_CountsTo_mVolts(gyro_dig);
                 //gyro_dig= gyro_dig - gyro_offset; 
                 gyro_ana_diff= abs(gyro_ana-gyro_ana_pre);
                 if(gyro_ana_diff <20){
                    if(gyro_ana > gyro_hig){
                        gyro_hig = gyro_ana;
                    }
                    if((gyro_ana < gyro_low) && (gyro_ana !=0 )){
                        gyro_low = gyro_ana;
                    }
                }
                gyro_ana_pre=gyro_ana;
                
            }
            if(gyro_ana_ref+2 < gyro_hig){
                rotation_bit = 1;
                rot_angle=(((gyro_hig-gyro_ana_ref)*100)/67);
            }
            else{
                rotation_bit = 0;
                rot_angle=(((gyro_ana_ref-gyro_low)*100)/67);
            }
            CyDelayUs(2);
        
        
            LCD_Position(0,1);
            LCD_PrintString("ANGLE");
            LCD_Position(0,8);
            LCD_PrintNumber(rot_angle);
            if(rotation_bit == 0){
                LCD_Position(1,0);
               LCD_PrintString("ANTI-CLOCKWISE");
            }
            else{
                LCD_Position(1,0);
                LCD_PrintString("CLOCKWISE");
            
            }
            
            gyro_hig=0;
            gyro_low=gyro_ana_ref;
            CyDelayUs(100);
        }
}







void mag_final()
{
        
        uint8 x_low=data_receive[0];
        uint8 x_high=data_receive[1];
        uint8 y_low=data_receive[2];
        uint8 y_high=data_receive[3];
        uint8 z_low=data_receive[4];
        uint8 z_high=data_receive[5];
        uint16 x_m;
        uint16 y_m;
        uint16 z_m;
        int i ;
        for(i=0;i<10000;i++){ 
        }
        data_trans2[0]=0x28;
        I2C_MasterWriteBuf(add_m,data_trans2,0x01,I2C_MODE_COMPLETE_XFER); 
        for(i=0;i<10000;i++){ 
        }
        
        I2C_MasterReadBuf(add_m,data_receive,0x06,I2C_MODE_COMPLETE_XFER);
        for(i=0;i<10000;i++){    
        }
        
        x_m= x_high*256 + x_low;
        y_m= y_high*256 + y_low;
        z_m= z_high*256 + z_low;
        LCD_ClearDisplay();
        /*LCD_Position(0, 2);
        LCD_PrintNumber(x_m);
        LCD_Position(1, 2);
        LCD_PrintNumber(y_m);
        
        LCD_Position(1, 8);
        LCD_PrintNumber(z_m);*/
        LCD_PrintString("DIRECTION TEST");
        
       
        mag_lcd(x_m,y_m,z_m);
        
        CyDelay(100);
      
}

void mag_lcd(uint16 x_m,uint16 y_m,uint16 z_m)
{
    if (((y_m < (y_m_p - 15)) || ( y_m > (y_m_p+15))) )
     
        if((((y_m < 50) && (y_m>0))||((y_m < 65535)&&(y_m>65510)))){
            LCD_Position(1, 5);
            LCD_PrintString("NORTH");
                  
          
    }
    
    y_m_p=y_m;
    x_m_p=x_m;    
    
}

void acc_final()
{
        
        uint8 x_low=data_receive[0];
        uint8 x_high=data_receive[1];
        uint8 y_low=data_receive[2];
        uint8 y_high=data_receive[3];
        uint8 z_low=data_receive[4];
        uint8 z_high=data_receive[5];
        uint16 x_a;
        uint16 y_a;
        uint16 z_a;
        int i ;
        
        data_trans2[0]=0x28;
        
        I2C_MasterWriteBuf(add_a,data_trans2,0x01,I2C_MODE_COMPLETE_XFER); 
        for(i=0;i<10000;i++){ 
        }
        
        I2C_MasterReadBuf(add_a,data_receive,0x06,I2C_MODE_COMPLETE_XFER);
        for(i=0;i<10000;i++){    
        }
        
        x_a= x_high*256 + x_low;
        y_a= y_high*256 + y_low;
        z_a= z_high*256 + z_low;
        
        LCD_Position(1, 0);
        LCD_PrintNumber(x_a);
        LCD_Position(1, 6);
        LCD_PrintNumber(y_a);
        LCD_Position(1, 11);
        LCD_PrintNumber(z_a);
        CyDelay(100);
        clear_LCD_line2();
        stepper_gyro(x_a);  
               
}





void initialize_mag()
{
//Data rate set to 100Hz and transfer data only after and MSB and LSB is received
 data_trans[0]=0x20;
 data_trans[1]=0xDc;
 data_trans[2]=0x60;
 data_trans[3]=0x00;
 data_trans[4]=0x08;
 data_trans[5]=0x60;
 complete_transfer_mag();
}
    
       
        /* Place your application code here. */
void initialize_acc()
{
//Data rate set to 100Hz and transfer data only after and MSB and LSB is received
 data_trans[0]=0x23;
 data_trans[1]=0x04;
 complete_transfer_acc();
 CyDelayUs(300);
 data_trans[0]=0x20;
 data_trans[1]=0x3f;
 complete_transfer_acc();

}

void complete_transfer_acc()
{
 uint8 i=I2C_MasterWriteBuf(add_a,data_trans,0x02,I2C_MODE_COMPLETE_XFER);      
}

void complete_transfer_mag()
{
 uint8 i=I2C_MasterWriteBuf(add_m,data_trans,0x06,I2C_MODE_COMPLETE_XFER);      
}

void clear_LCD_line2()
{
    int i;
for (i=0;i<=15;i++)
{
    LCD_Position(1,i); 
    LCD_PutChar(' ');
}
}
void delay_surplus()
{
    int i,j;
    for (i=1;i<=10000;i++){
        for (j=0;j<=100000;j++){
            int k= k+1;
            k=k-1;
        }
    }
}


void lcd_initalize()
{
    LCD_Position(0, 0); // The first argument is the row number, the second is the 
	                      // character that the cursor will be positioned to.
    LCD_PrintString("X     Y    Z    "); // Writes this string to the LCD.
}
void lcd_matlab_gyro()
{
    LCD_ClearDisplay();
    LCD_Position(0, 0); // The first argument is the row number, the second is the 
	                      // character that the cursor will be positioned to.
    LCD_PrintString("Oscilloscope-Gyro"); // Writes this string to the LCD.
}

void lcd_matlab_acc()
{
    LCD_ClearDisplay();
    LCD_Position(0, 0); // The first argument is the row number, the second is the 
	                      // character that the cursor will be positioned to.
    LCD_PrintString("MATLAB -- ACC  "); // Writes this string to the LCD.
}


void lcd_matlab_mag()
{
    LCD_ClearDisplay();
    LCD_Position(0, 0); // The first argument is the row number, the second is the 
	                      // character that the cursor will be positioned to.
    LCD_PrintString("MATLAB -- MAG  "); // Writes this string to the LCD.
}





void stepper_gyro(int acc_data)
{
    int steps;
    int relative_pos;
    if ( (acc_data < (previous_data - 130)) || ( acc_data > (previous_data+130))){
        
        if(acc_data > previous_data){
            
                relative_pos = acc_data-previous_data;
            
            if( relative_pos < 0x7fff ){
                
                steps=((relative_pos*514)/(65536));
                move_forward(steps);   
            }
            else{
                steps=(((65536-relative_pos)*514)/(65536));
                move_backward(steps);
            }
            
        }
            
        if(acc_data < previous_data){
            relative_pos = previous_data-acc_data;
            steps=((relative_pos*514)/(65536));
            if( relative_pos < 0x7fff){
                steps=((relative_pos*514)/(65536));
                move_backward(steps);   
            }
            else{
                steps=(((65536-relative_pos)*514)/(65536));
                move_forward(steps);
            }
        }    
        previous_data = acc_data; 
    }
}


void stepper_motor_test()
      {
        
        move_forward(514);
        CyDelay(3000); 
      }
    
    
void move_forward(int steps)
        {
            int i;
            for(i=0;i<steps;i++)
            {
                blue_Write(1);
                pink_Write(0);
                yellow_Write(0);
                orange_Write(0);
                CyDelayUs(2000);
                blue_Write(1);
                pink_Write(1);
                yellow_Write(0);
                orange_Write(0);
                CyDelayUs(2000);
                blue_Write(0);
                pink_Write(1);
                yellow_Write(0);
                orange_Write(0);
                CyDelayUs(2000);
                blue_Write(0);
                pink_Write(1);
                yellow_Write(1);
                orange_Write(0);
                CyDelayUs(2000);
                blue_Write(0);
                pink_Write(0);
                yellow_Write(1);
                orange_Write(0);
                CyDelayUs(2000);
                blue_Write(0);
                pink_Write(0);
                yellow_Write(1);
                orange_Write(1);
                CyDelayUs(2000);
                blue_Write(0);
                pink_Write(0);
                yellow_Write(0);
                orange_Write(1);
                CyDelayUs(2000);
                blue_Write(1);
                pink_Write(0);
                yellow_Write(0);
                orange_Write(1);
                CyDelayUs(2000);
            }
        }
        
   void    move_backward(int steps)
        {
            int i;
            for(i=0;i<steps;i++)
            {
                orange_Write(1);
                yellow_Write(0);
                pink_Write(0);
                blue_Write(0);
                CyDelayUs(2000);
                orange_Write(1);
                yellow_Write(1);
                pink_Write(0);
                blue_Write(0);
                CyDelayUs(2000);
                orange_Write(0);
                yellow_Write(1);
                pink_Write(0);
                blue_Write(0);
                CyDelayUs(2000);
                orange_Write(0);
                yellow_Write(1);
                pink_Write(1);
                blue_Write(0);
                CyDelayUs(2000);
                orange_Write(0);
                yellow_Write(0);
                pink_Write(1);
                blue_Write(0);
                CyDelayUs(2000);
                orange_Write(0);
                yellow_Write(0);
                pink_Write(1);
                blue_Write(1);
                CyDelayUs(2000);
                orange_Write(0);
                yellow_Write(0);
                pink_Write(0);
                blue_Write(1);
                CyDelayUs(2000);
                orange_Write(1);
                yellow_Write(0);
                pink_Write(0);
                blue_Write(1);
                CyDelayUs(2000);
            }
        }

/* [] END OF FILE */
