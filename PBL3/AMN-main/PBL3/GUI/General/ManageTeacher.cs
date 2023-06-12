﻿using MySql.Data.MySqlClient;
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
    public partial class ManageTeacher : Form
    {
        TeacherClass teacher = new TeacherClass();
        CourseClass course = new CourseClass();
        public ManageTeacher()
        {
            InitializeComponent();
        }
        public void showTable()
        {
            DataGridView_student.DataSource = teacher.getTeacherlist(new MySqlCommand("SELECT * FROM `teacher`"));
            DataGridViewImageColumn imageColumn = new DataGridViewImageColumn();
            DataGridViewImageColumn dataGridViewImageColumn = (DataGridViewImageColumn)DataGridView_student.Columns[10];
            imageColumn = dataGridViewImageColumn;
            imageColumn.ImageLayout = DataGridViewImageCellLayout.Zoom;
        }
        private void DataGridView_teacher_Click(object sender, EventArgs e)
        {
            textBox_id.Text = DataGridView_student.CurrentRow.Cells[0].Value.ToString();
            textBox_Fname.Text = DataGridView_student.CurrentRow.Cells[1].Value.ToString();
            textBox_Lname.Text = DataGridView_student.CurrentRow.Cells[2].Value.ToString();
            txtusername.Text = DataGridView_student.CurrentRow.Cells[5].Value.ToString();
            txtpassword.Text = DataGridView_student.CurrentRow.Cells[6].Value.ToString();

            dateTimePicker1.Value = (DateTime)DataGridView_student.CurrentRow.Cells[3].Value;
            if (DataGridView_student.CurrentRow.Cells[4].Value.ToString() == "Male")
                radioButton_male.Checked = true;

            textBox_phone.Text = DataGridView_student.CurrentRow.Cells[7].Value.ToString();
            textBox_address.Text = DataGridView_student.CurrentRow.Cells[8].Value.ToString();
            comboBox1.ResetText();
            byte[] img = (byte[])DataGridView_student.CurrentRow.Cells[10].Value;
            MemoryStream ms = new MemoryStream(img);
            pictureBox_student.Image = Image.FromStream(ms);
        }
        private void manageTeacher_load(object sender, EventArgs e)
        {
            showTable();
            comboBox1.DataSource = course.getCourse(new MySqlCommand("SELECT * FROM `course`"));
            comboBox1.DisplayMember = "CourseName";
            comboBox1.ValueMember = "CourseName";
        }

        private void button_upload_Click(object sender, EventArgs e)
        {
            OpenFileDialog opf = new OpenFileDialog();
            opf.Filter = "Select Photo(*.jpg;*.png;*.gif)|*.jpg;*.png;*.gif";

            if (opf.ShowDialog() == DialogResult.OK)
                pictureBox_student.Image = Image.FromFile(opf.FileName);
        }

        private void button_clear_Click(object sender, EventArgs e)
        {
            textBox_id.Clear();
            textBox_Fname.Clear();
            textBox_Lname.Clear();
            textBox_phone.Clear();
            textBox_address.Clear();
            txtusername.Clear();
            txtpassword.Clear();
            comboBox1.ResetText();
            radioButton_male.Checked = true;
            dateTimePicker1.Value = DateTime.Now;
            pictureBox_student.Image = null;
        }
        bool verify()
        {
            if ((textBox_Fname.Text == "") || (textBox_Lname.Text == "") ||
                (textBox_phone.Text == "") || (textBox_address.Text == "") ||
                (pictureBox_student.Image == null))
            {
                return false;
            }
            else
                return true;
        }
        private void button_update_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(textBox_id.Text);
            string fname = textBox_Fname.Text;
            string lname = textBox_Lname.Text;
            DateTime bdate = dateTimePicker1.Value;
            string phone = textBox_phone.Text;
            string address = textBox_address.Text;
            string gender = radioButton_male.Checked ? "Male" : "Female";
            string username = txtusername.Text;
            string password = txtpassword.Text;
            string subject = comboBox1.SelectedValue.ToString();

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
                    MemoryStream ms = new MemoryStream();
                    pictureBox_student.Image.Save(ms, pictureBox_student.Image.RawFormat);
                    byte[] img = ms.ToArray();
                    if (teacher.updateTeacher(id, fname, lname, bdate, gender, username, password, phone, address,subject, img))
                    {
                        showTable();
                        MessageBox.Show("Teacher data update", "Update Teacher", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        button_clear.PerformClick();
                    }
                }
                catch (Exception ex)

                {
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("Empty Field", "Update Teacher", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void button_delete_Click(object sender, EventArgs e)
        {
            if (textBox_id.Text == "")
            {
                MessageBox.Show("Field Error- we need Teacher id", "Delete Teacher", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                foreach (DataGridViewRow row in DataGridView_student.SelectedRows)
                {
                    int rowId = Convert.ToInt32(row.Cells[0].Value);
                    if (rowId > 0)
                    {
                        if (teacher.deleteTeacher(rowId))
                        {
                            continue;
                        }
                    }
                }
                showTable();
                MessageBox.Show("Teacher Removed", "Remove Teacher", MessageBoxButtons.OK, MessageBoxIcon.Information);
                button_clear.PerformClick();
            }    
                
        }
    }
}
