using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PBL3
{
    public partial class Register_Teacher : Form
    {
        TeacherClass teacher = new TeacherClass();
        CourseClass course = new CourseClass();
        public Register_Teacher()
        {
            InitializeComponent();
        }

        private void Teacher_Load(object sender, EventArgs e)
        {
            showTable();
            comboBox1.DataSource = course.getCourse(new MySqlCommand("SELECT * FROM `course`"));
            comboBox1.DisplayMember = "CourseName";
            comboBox1.ValueMember = "CourseName";
        }

        public void showTable()
        {
            DataGridView_student.DataSource = teacher.getTeacherlist(new MySqlCommand("SELECT * FROM `teacher`"));
            DataGridViewImageColumn imageColumn = new DataGridViewImageColumn();
            DataGridViewImageColumn dataGridViewImageColumn = (DataGridViewImageColumn)DataGridView_student.Columns[10];
            imageColumn = dataGridViewImageColumn;
            imageColumn.ImageLayout = DataGridViewImageCellLayout.Zoom;
        }
        bool verify()
        {
            if ((textBox_Fname.Text == "") || (textBox_Lname.Text == "") ||
                (textBox_phone.Text == "") || (textBox_address.Text == "") ||
                (pic_teacher.Image == null))
            {
                return false;
            }
            else
                return true;
        }
        private void button_upload_Click_1(object sender, EventArgs e)
        {
            OpenFileDialog opf = new OpenFileDialog();
            opf.Filter = "Select Photo(*.jpg;*.png;*.gif)|*.jpg;*.png;*.gif";

            if (opf.ShowDialog() == DialogResult.OK)
                pic_teacher.Image = Image.FromFile(opf.FileName);
        }

        private void button_clear_Click_1(object sender, EventArgs e)
        {
            textBox_Fname.Clear();
            textBox_Lname.Clear();
            textBox_phone.Clear();
            textBox_address.Clear();
            txtpassword.Clear();
            txtusername.Clear();
            comboBox1.ResetText();
            radioButton_male.Checked = true;
            dateTimePicker1.Value = DateTime.Now;
            pic_teacher.Image = null;
        }

        private void button_add_Click_1(object sender, EventArgs e)
        {
            string fname = textBox_Fname.Text;
            string lname = textBox_Lname.Text;
            DateTime bdate = dateTimePicker1.Value;
            string phone = textBox_phone.Text;
            string username = txtusername.Text;
            string password = txtpassword.Text;
            string address = textBox_address.Text;
            string subject = comboBox1.Text;
            string gender = radioButton_male.Checked ? "Male" : "Female";


            //we need to check student age between 10 and 100

            int born_year = dateTimePicker1.Value.Year;
            int this_year = DateTime.Now.Year;
            if ((this_year - born_year) < 10 || (this_year - born_year) > 100)
            {
                MessageBox.Show("The student age must be between 10 and 100", "Invalid Birthdate", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (verify())
            {
                try
                {
                    // to get photo from picture box
                    MemoryStream ms = new MemoryStream();
                    pic_teacher.Image.Save(ms, pic_teacher.Image.RawFormat);
                    byte[] img = ms.ToArray();
                    if (teacher.insertTeacher(fname, lname, bdate, gender, phone, username, password, address, subject, img))
                    {
                        showTable();
                        MessageBox.Show("New Teacher Added", "Add Teacher", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                }
                catch (Exception ex)

                {
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("Empty Field", "Add Student", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
    }
}
