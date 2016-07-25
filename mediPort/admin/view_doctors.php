<?php session_start();
	include 'includes/db.php';
	if(isset($_SESSION['user']) && isset($_SESSION['password']) == true){
		$sel_sql = "SELECT * FROM users WHERE user_email = '$_SESSION[user]' AND user_password = '$_SESSION[password]'";
		if($run_sql = mysqli_query($conn, $sel_sql)){
			while($rows = mysqli_fetch_assoc($run_sql)){
				if(mysqli_num_rows($run_sql) == 1 ){
					if($rows['role'] == 'admin'){
					} else {
						header('Location:../index.php');
					}
				} else{
					header('Location:../index.php');
				}
			}
		}
	} else {
		header('Location:../index.php');
	}
	$result = '';
	
	$per_page = 5;
	if(isset($_GET['page'])){
		$page = $_GET['page'];
	} else{
		$page = 1;
	}
	$start_from = ($page-1) * $per_page;
	
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin Panel</title>
		<link rel="stylesheet" href="../../bootstrap/css/bootstrap.css">
		<script src="../../js/jquery.js"></script>
		<script src="../../bootstrap/js/bootstrap.js"></script>
		<script>
			
		</script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/sidebar.php';?>
		<div class="col-lg-10">
		<div style="width:100px;height:50px;"></div>
		<?php 
			echo $result;
		?>
			<div class="panel panel-primary">
				<div class="panel-heading"><h3>Doctors</h3></div>
				<div class="panel-body">
					<table  class="table table-condensed table-striped">
						<thead>
							<tr>
								<th>Name</th>
								<th>Speciality</th>
								<th>City</th>
								<th>Fees</th>
								<th>Qualification</th>
								<th>Clinic Address</th>
								<th>Clinic Timings</th>
								<th>Home Adress</th>
								<th>Contact No.</th>
								<th>Alternate Contact No.</th>
								<th>Email</th>
								<th>Date of Birth</th>
								<th>Years of exp.</th>
								<th>Gender</th>
							</tr>
							
						</thead>
						<tbody>
							<?php
								//$sql = "SELECT * FROM posts ORDER BY ID DESC";
								$i=1;
								$color="";
								$sql = "SELECT * FROM doctors order by f_name LIMIT $start_from,$per_page";
								$run = mysqli_query($conn,$sql);
								while($rows = mysqli_fetch_assoc($run)){
									echo '
									<tr>
								
										<td class="'.$color.'">'.ucfirst($rows['f_name']).' '.ucfirst($rows['l_name']).'</td>
										<td class="'.$color.'">'.ucfirst($rows['speciality']).'</td>
										<td class="'.$color.'">'.$rows['city'].'</td>
										<td class="'.$color.'">'.$rows['fees'].'</td>
										<td class="'.$color.'">'.$rows['qualification'].'</td>
										<td class="'.$color.'">'.$rows['clinic_address'].'</td>
										<td class="'.$color.'">'.$rows['timings'].'</td>
										<td class="'.$color.'">'.$rows['home_address'].'</td>
										<td class="'.$color.'">'.$rows['contact_no'].'</td>
										<td class="'.$color.'">'.$rows['alt_contact_no'].'</td>
										<td class="'.$color.'">'.$rows['email'].'</td>
										<td class="'.$color.'">'.$rows['dob'].'</td>
										<td class="'.$color.'">'.$rows['years_of_exp'].'</td>
										<td class="'.$color.'">'.substr(ucfirst($rows['gender']),0,1).'</td>
									</tr>
									';
									$i++;
								}
							?>
							
							
						</tbody>
					</table>
				</div>
			</div>
			<div class="text-center">
				<ul class="pagination">
				<?php
					$pagination_sql = "SELECT * FROM doctors";
					$run_pagination = mysqli_query($conn, $pagination_sql);

					$count = mysqli_num_rows($run_pagination);
					
					$total_pages = ceil($count/$per_page);
					
					for($i=1;$i<=$total_pages;$i++){
						echo '<li><a href="view_doctors.php?page='.$i.'">'.$i.'</a></li>';
					}
					
				?>			
				</ul>
			</div>
			
		</div>
		<footer></footer>
	</body>
</html>